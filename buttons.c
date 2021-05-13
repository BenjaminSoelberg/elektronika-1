#include "buttons.h"
#include "gpio.h"
#include "driverlib_ng.h"

bool volatile timer_running = false;

void Buttons_timer_stop(void);

void Buttons_init(void)
{
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P2, GPIO_PIN3);
    GPIO_selectInterruptEdge(GPIO_PORT_P2, GPIO_PIN3, GPIO_HIGH_TO_LOW_TRANSITION);

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
    GPIO_clearInterrupt(GPIO_PORT_P2, GPIO_PIN3);
    GPIO_enableInterrupt(GPIO_PORT_P2, GPIO_PIN3);
}

void Buttons_stop(void)
{
    GPIO_disableInterrupt(GPIO_PORT_P2, GPIO_PIN3);
    Buttons_timer_stop();
}

void Buttons_timer_start(void)
{
    unsigned short lock;
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
    unsigned short lock;
    ENTER_CRITICAL_SECTION(lock);
    if (timer_running) {
        Timer_A_stop(BUTTONS_TIMER_BASE);
        timer_running = false;
    }
    EXIT_CRITICAL_SECTION(lock);
}

#pragma vector=PORT2_VECTOR
__interrupt void Buttons_pressed_isr(void)
{
#ifdef CONFIG_BUTTONS_PRESSED_BLINK_ALIVE
    P1DIR |= 0x01;
    P1OUT ^= 0x01;
#endif

    Buttons_timer_start();
    GPIO_clearInterrupt(GPIO_PORT_P2, GPIO_PIN3);
}

#pragma vector=BUTTONS_TIMER_VECTOR
__interrupt void Buttons_timer_isr(void)
{
#ifdef CONFIG_BUTTONS_TIMER_BLINK_ALIVE
    P1DIR |= 0x02;
    P1OUT ^= 0x02;
#endif

    uint16_t status = GPIO_getInputPinValues(GPIO_PORT_P2, GPIO_PIN3);
    if (BIT_IS_SET(status, GPIO_PIN3)) {
        Buttons_timer_stop();
    }

    Timer_A_clearTimerInterrupt(BUTTONS_TIMER_BASE);
}
