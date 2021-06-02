#include "debounce.h"

void update_button(uint8_t *button_history, bool state)
{
    *button_history = (*button_history & 0b10000000) | ((*button_history & 0b00111111) << 1) | state;
}

bool is_button_up(uint8_t *button_history) //TODO: Not sure this works or how to use
{
    return *button_history & 0b10000000 == 0;
}

bool is_button_down(uint8_t *button_history) //TODO: Not sure this works or how to use
{
    return *button_history & 0b10000000 > 0;
}

bool is_button_pressed(uint8_t *button_history)
{
    if ((*button_history & MASK) == MASK_PRESSED) {
        *button_history = CONFIRMED_PRESS;
        return true;
    }
    return false;
}

bool is_button_released(uint8_t *button_history)
{
    if ((*button_history & MASK) == MASK_RELEASED) {
        *button_history = CONFIRMED_RELEASE;
        return true;
    }
    return false;
}
