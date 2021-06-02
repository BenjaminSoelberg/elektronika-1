#ifndef __DEBOUNCE_H__
#define __DEBOUNCE_H__

#include "elektronika.h"

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

// See https://hackaday.com/2015/12/10/embed-with-elliot-debounce-your-noisy-buttons-part-ii/#comment-2834792

#define MASK_PRESSED 0b00000111
#define MASK_RELEASED 0b11000000
#define MASK (MASK_PRESSED | MASK_RELEASED)
#define CONFIRMED_PRESS 0b11111111
#define CONFIRMED_RELEASE 0b00000000

extern void update_button(uint8_t *button_history, bool state);
extern bool is_button_up(uint8_t *button_history);
extern bool is_button_down(uint8_t *button_history);
extern bool is_button_pressed(uint8_t *button_history);
extern bool is_button_released(uint8_t *button_history);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif /* __DEBOUNCE_H__ */
