#include "buttons.h"
#include "gpio.h"


#define ALL_BUTTON_PINS (GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3)
#define BUTTON_PORT GPIO_PORT_P1

bool volatile timer_running = false;

void Buttons_timer_stop(void);

void Buttons_init(void)
{
    GPIO_setAsInputPinWithPullDownResistor(BUTTON_PORT, ALL_BUTTON_PINS);
    GPIO_selectInterruptEdge(BUTTON_PORT, ALL_BUTTON_PINS, GPIO_LOW_TO_HIGH_TRANSITION);

    Timer_A_initUpModeParam parameters = {
            .clockSource = TIMER_A_CLOCKSOURCE_ACLK,
            .clockSourceDivider = TIMER_A_CLOCKSOURCE_DIVIDER_1,
            .timerPeriod = (CONFIG_LFO_HZ - 1) / BUTTONS_POLL_HZ,
            .timerInterruptEnable_TAIE = TIMER_A_TAIE_INTERRUPT_ENABLE,
            .captureCompareInterruptEnable_CCR0_CCIE = TIMER_A_CCIE_CCR0_INTERRUPT_DISABLE,
            .timerClear = TIMER_A_DO_CLEAR,
            .startTimer = false
    };

    Timer_A_initUpMode(BUTTONS_TIMER_BASE, &parameters);
}

void Buttons_start(void)
{
    GPIO_enableInterrupt(BUTTON_PORT, ALL_BUTTON_PINS);
}

void Buttons_stop(void)
{
    GPIO_disableInterrupt(BUTTON_PORT, ALL_BUTTON_PINS);
    Buttons_timer_stop();
}

void Buttons_timer_start(void)
{
    unsigned short volatile lock;
    ENTER_CRITICAL_SECTION(lock);
    if (!timer_running) {
        Timer_A_clear(BUTTONS_TIMER_BASE);
        Timer_A_startCounter(BUTTONS_TIMER_BASE, TIMER_A_UP_MODE);
        timer_running = true;
    }
    EXIT_CRITICAL_SECTION(lock);
}

void Buttons_timer_stop(void)
{
    unsigned short volatile lock;
    ENTER_CRITICAL_SECTION(lock);
    if (!timer_running) {
        Timer_A_stop(BUTTONS_TIMER_BASE);
        timer_running = false;
    }
    EXIT_CRITICAL_SECTION(lock);
}

#pragma vector=PORT1_VECTOR
__interrupt void Buttons_pressed_isr(void)
{
#ifdef CONFIG_BUTTONS_PRESSED_BLINK_ALIVE
    P1DIR |= 0x01;
    P1OUT ^= 0x01;
#endif

    Buttons_timer_start();
    GPIO_clearInterrupt(BUTTON_PORT, ALL_BUTTON_PINS);
}

#pragma vector=BUTTONS_TIMER_VECTOR
__interrupt void Buttons_timer_isr(void)
{
#ifdef CONFIG_BUTTONS_TIMER_BLINK_ALIVE
    P1DIR |= 0x02;
    P1OUT ^= 0x02;
#endif

    //if no buttons are pressed then stop the poll timer ???
    uint8_t status = GPIO_getInputPinValue(BUTTON_PORT, ALL_BUTTON_PINS);
    if (!status) {
        Buttons_timer_stop();
    }

    Timer_A_clearTimerInterrupt(BUTTONS_TIMER_BASE);
}
