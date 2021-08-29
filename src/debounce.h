#ifndef __DEBOUNCE_H__
#define __DEBOUNCE_H__

#include "elektronika.h"

// See https://hackaday.com/2015/12/10/embed-with-elliot-debounce-your-noisy-buttons-part-ii/#comment-2834792

#define MASK_STATE_BIT 0b10000000
#define MASK_PRESSED  0b00000111
#define MASK_RELEASED (0b01000000 | MASK_STATE_BIT)
#define MASK (MASK_PRESSED | MASK_RELEASED)
#define MASK_HISTORY_BITS 0b01111111
#define CONFIRMED_PRESS (MASK_HISTORY_BITS | MASK_STATE_BIT)
#define CONFIRMED_RELEASE 0b00000000

void update_button(uint8_t *button_history, bool button_state);
bool is_button_up(uint8_t *button_history);
bool is_button_down(uint8_t *button_history);
bool is_button_pressed(uint8_t *button_history);
bool is_button_released(uint8_t *button_history);
void clear_button(uint8_t *button_history);

#endif /* __DEBOUNCE_H__ */
