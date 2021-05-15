#include "display.h"

void Display_clear_pin_state();
uint8_t screen[] = {0, 0, 0, 0};
uint8_t volatile index = 0;

#define DISPLAY_SEGMENT_PORT GPIO_PORT_P1
#define DISPLAY_SEGMENT_PINS (GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7)
#define DISPLAY_DIGIT_1_PORT GPIO_PORT_P2
#define DISPLAY_DIGIT_1_PIN  GPIO_PIN2
#define DISPLAY_DIGIT_2_PORT GPIO_PORT_P3
#define DISPLAY_DIGIT_2_PIN  GPIO_PIN0
#define DISPLAY_DIGIT_3_PORT GPIO_PORT_P3
#define DISPLAY_DIGIT_3_PIN  GPIO_PIN1
#define DISPLAY_DIGIT_4_PORT GPIO_PORT_P3
#define DISPLAY_DIGIT_4_PIN  GPIO_PIN2

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

    GPIO_setAsOutputPin(DISPLAY_SEGMENT_PORT, DISPLAY_SEGMENT_PINS);
    GPIO_setAsOutputPin(DISPLAY_DIGIT_1_PORT, DISPLAY_DIGIT_1_PIN);
    GPIO_setAsOutputPin(DISPLAY_DIGIT_2_PORT, DISPLAY_DIGIT_2_PIN);
    GPIO_setAsOutputPin(DISPLAY_DIGIT_3_PORT, DISPLAY_DIGIT_3_PIN);
    GPIO_setAsOutputPin(DISPLAY_DIGIT_4_PORT, DISPLAY_DIGIT_4_PIN);

    Display_clear_pin_state();
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
    Display_clear_pin_state();
}

void Display_clear_pin_state(void)
{
    GPIO_setOutputLowOnPin(DISPLAY_SEGMENT_PORT, DISPLAY_SEGMENT_PINS);
    GPIO_setOutputHighOnPin(DISPLAY_DIGIT_1_PORT, DISPLAY_DIGIT_1_PIN);
    GPIO_setOutputHighOnPin(DISPLAY_DIGIT_2_PORT, DISPLAY_DIGIT_2_PIN);
    GPIO_setOutputHighOnPin(DISPLAY_DIGIT_3_PORT, DISPLAY_DIGIT_3_PIN);
    GPIO_setOutputHighOnPin(DISPLAY_DIGIT_4_PORT, DISPLAY_DIGIT_4_PIN);
}

void Display_update(uint8_t *data)
{
    memcpy(&screen, data, sizeof(screen));
}

#pragma vector=DISPLAY_TIMER_VECTOR
__interrupt void Display_multiplex_isr(void)
{
    switch (index)  //TODO: Make an array of port and pin instead...
    {
        case 0: {
            GPIO_setOutputHighOnPin(DISPLAY_DIGIT_4_PORT, DISPLAY_DIGIT_4_PIN);
            GPIO_setOutputPinsOnPort(DISPLAY_SEGMENT_PORT, screen[index]);
            GPIO_setOutputLowOnPin(DISPLAY_DIGIT_1_PORT, DISPLAY_DIGIT_1_PIN);
            index++;
            break;
        }
        case 1: {
            GPIO_setOutputHighOnPin(DISPLAY_DIGIT_1_PORT, DISPLAY_DIGIT_1_PIN);
            GPIO_setOutputPinsOnPort(DISPLAY_SEGMENT_PORT, screen[index]);
            GPIO_setOutputLowOnPin(DISPLAY_DIGIT_2_PORT, DISPLAY_DIGIT_2_PIN);
            index++;
            break;
        }
        case 2: {
            GPIO_setOutputHighOnPin(DISPLAY_DIGIT_2_PORT, DISPLAY_DIGIT_2_PIN);
            GPIO_setOutputPinsOnPort(DISPLAY_SEGMENT_PORT, screen[index]);
            GPIO_setOutputLowOnPin(DISPLAY_DIGIT_3_PORT, DISPLAY_DIGIT_3_PIN);
            index++;
            break;
        }
        case 3: {
            GPIO_setOutputHighOnPin(DISPLAY_DIGIT_3_PORT, DISPLAY_DIGIT_3_PIN);
            GPIO_setOutputPinsOnPort(DISPLAY_SEGMENT_PORT, screen[index]);
            GPIO_setOutputLowOnPin(DISPLAY_DIGIT_4_PORT, DISPLAY_DIGIT_4_PIN);
            index = 0;
        }
    }

    Timer_A_clearTimerInterrupt(DISPLAY_TIMER_BASE);
}
