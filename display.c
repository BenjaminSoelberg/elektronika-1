#include "display.h"
#include "gpio.h"

uint8_t screen[] = {0, 0, 0, 0};
uint8_t volatile index = 0;

void Display_init(void)
{
    Timer_A_initUpModeParam parameters = {
            .clockSource = TIMER_A_CLOCKSOURCE_ACLK,
            .clockSourceDivider = TIMER_A_CLOCKSOURCE_DIVIDER_1,
            .timerPeriod = (CONFIG_LFO_HZ - 1) / DISPLAY_MULTIPLEX_HZ,
            .timerInterruptEnable_TAIE = TIMER_A_TAIE_INTERRUPT_ENABLE,
            .captureCompareInterruptEnable_CCR0_CCIE = TIMER_A_CCIE_CCR0_INTERRUPT_DISABLE,
            .timerClear = TIMER_A_DO_CLEAR,
            .startTimer = false
    };

    Timer_A_initUpMode(DISPLAY_TIMER_BASE, &parameters);

    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN6 | GPIO_PIN7);
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7);
    GPIO_setAsOutputPin(GPIO_PORT_P3, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2);
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN6 | GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2);
}

void Display_start(void)
{
    index = 0;
    Timer_A_clear(DISPLAY_TIMER_BASE);
    Timer_A_startCounter(DISPLAY_TIMER_BASE, TIMER_A_UP_MODE);
}

void Display_stop(void)
{
    Timer_A_stop(DISPLAY_TIMER_BASE);
    // TODO: Display pin ports off etc.
}

void Display_update(uint8_t *data)
{
    memcpy(&screen, data, sizeof(screen));
}

// Display timer interrupt service routine
#pragma vector=DISPLAY_TIMER_VECTOR
__interrupt void Display_multiplex_isr(void)
{
#ifdef CONFIG_DISPLAY_BLINK_ALIVE
    P1DIR |= 0x01;
    P1OUT ^= 0x01;
#endif

    uint8_t segment = screen[index];

    //TODO:Outport bits to display

    index = index == sizeof(screen) - 1 ? 0 : index++;

    Timer_A_clearTimerInterrupt(DISPLAY_TIMER_BASE);
}
