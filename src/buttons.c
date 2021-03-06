#include "buttons.h"
#include "debounce.h"

volatile bool timer_running = false;

uint8_t button_bits[] =
{
    GPIO_PIN0,
    GPIO_PIN1,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6
};

uint8_t button_history[sizeof(button_bits)];

bool Buttons_is_button_up(BUTTONS button)
{
    return is_button_up(&button_history[button]);
}

bool Buttons_is_button_down(BUTTONS button)
{
    return is_button_down(&button_history[button]);
}

bool Buttons_is_button_pressed(BUTTONS button)
{
    return is_button_pressed(&button_history[button]);
}

bool Buttons_is_button_released(BUTTONS button)
{
    return is_button_released(&button_history[button]);
}

void Buttons_clear_button(BUTTONS button)
{
    clear_button(&button_history[button]);
}

void Buttons_timer_stop(void);

void Buttons_init(void)
{
    GPIO_setAsInputPinWithPullDownResistor(BUTTONS_PORT, BUTTON_PINS);
    GPIO_selectInterruptEdge(BUTTONS_PORT, BUTTON_PINS, GPIO_LOW_TO_HIGH_TRANSITION);

    Timer_A_initUpModeParam parameters = {
       .clockSource = TIMER_A_CLOCKSOURCE_ACLK,
       .clockSourceDivider = TIMER_A_CLOCKSOURCE_DIVIDER_1,
       .timerPeriod = (CONFIG_LFO_HZ - 1) / BUTTONS_POLL_HZ,
       .timerInterruptEnable_TAIE = TIMER_A_TAIE_INTERRUPT_ENABLE,
       .captureCompareInterruptEnable_CCR0_CCIE =
       TIMER_A_CCIE_CCR0_INTERRUPT_DISABLE,
       .timerClear = TIMER_A_DO_CLEAR,
       .startTimer = false
    };

    Timer_A_initUpMode(BUTTONS_TIMER_BASE, &parameters);
}

void Buttons_start(void)
{
    unsigned short state;
    ENTER_CRITICAL_SECTION(state);
    GPIO_clearInterrupt(BUTTONS_PORT, BUTTON_PINS);
    GPIO_enableInterrupt(BUTTONS_PORT, BUTTON_PINS);
    EXIT_CRITICAL_SECTION(state);
}

void Buttons_stop(void)
{
    unsigned short state;
    ENTER_CRITICAL_SECTION(state);
    GPIO_disableInterrupt(BUTTONS_PORT, BUTTON_PINS);
    GPIO_clearInterrupt(BUTTONS_PORT, BUTTON_PINS);
    Buttons_timer_stop();
    EXIT_CRITICAL_SECTION(state);
}

void Buttons_timer_start(void)
{
    unsigned short state;
    ENTER_CRITICAL_SECTION(state);
    if (!timer_running) {
        Timer_A_clear(BUTTONS_TIMER_BASE);
        Timer_A_startCounter(BUTTONS_TIMER_BASE, TIMER_A_UP_MODE);
        timer_running = true;
    }
    EXIT_CRITICAL_SECTION(state);
}

void Buttons_timer_stop(void)
{
    unsigned short state;
    ENTER_CRITICAL_SECTION(state);
    if (timer_running) {
        Timer_A_stop(BUTTONS_TIMER_BASE);
        timer_running = false;
    }
    EXIT_CRITICAL_SECTION(state);
}

#pragma vector=BUTTONS_VECTOR
__interrupt void Buttons_pressed_isr(void)
{
    if (GPIO_getInterruptStatus(BUTTONS_PORT, BUTTON_PINS)) {
        Buttons_timer_start();
    }
    GPIO_clearInterrupt(BUTTONS_PORT, BUTTON_PINS);
}

#pragma vector=BUTTONS_TIMER_VECTOR
__interrupt void Buttons_timer_isr(void)
{
    bool all_released = true;
    uint8_t buttons = GPIO_getInputPinValues(BUTTONS_PORT, BUTTON_PINS);
    for (uint8_t i = 0; i < sizeof(button_bits); i++) {
        update_button(&button_history[i], buttons & button_bits[i]);
        // I'm not very pleased with the two calls below but it saves the main loop from calling them.
        is_button_pressed(&button_history[i]);
        is_button_released(&button_history[i]);
        if (button_history[i] != CONFIRMED_RELEASE) {
            all_released = false;
        }
    }

    if (all_released) {
        Buttons_timer_stop();
    }

    __low_power_mode_off_on_exit(); // Release cpu to main loop

    Timer_A_clearTimerInterrupt(BUTTONS_TIMER_BASE);
}
