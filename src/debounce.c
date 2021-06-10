#include "debounce.h"

// No sync needed within calls from the the interrupt function
void update_button(uint8_t *button_history, bool button_state)
{
    *button_history = (*button_history & MASK_STATE_BIT) | ((*button_history & (MASK_HISTORY_BITS >> 1)) << 1) | button_state;
}

bool is_button_up(uint8_t *button_history)
{
    unsigned short state;
    ENTER_CRITICAL_SECTION(state);
    bool result = (*button_history & MASK_STATE_BIT) == 0;
    EXIT_CRITICAL_SECTION(state);
    return result;
}

bool is_button_down(uint8_t *button_history)
{
    unsigned short state;
    ENTER_CRITICAL_SECTION(state);
    bool result = (*button_history & MASK_STATE_BIT) == MASK_STATE_BIT;
    EXIT_CRITICAL_SECTION(state);
    return result;
}

void clear_button(uint8_t *button_history)
{
    unsigned short state;
    ENTER_CRITICAL_SECTION(state);
    *button_history = CONFIRMED_RELEASE;
    EXIT_CRITICAL_SECTION(state);
}

// No sync needed within calls from the the interrupt function
bool is_button_pressed(uint8_t *button_history)
{
    bool result = false;
    if ((*button_history & MASK) == MASK_PRESSED) {
        *button_history = CONFIRMED_PRESS;
        result = true;
    }
    return result;
}

// No sync needed within calls from the the interrupt function
bool is_button_released(uint8_t *button_history)
{
    bool result = false;
    if ((*button_history & MASK) == MASK_RELEASED) {
        *button_history = CONFIRMED_RELEASE;
        result = true;
    }
    return result;
}
