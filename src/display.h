#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include "elektronika.h"

#define AS1115_SLAVE_ADDRESS 0x00
#define I2C_BASE EUSCI_B0_BASE
#define CLEAR true
#define NO_CLEAR false

void Display_init(void);
void Display_start(bool clear);
void Display_stop(void);
void Display_clear(void);
void Display_fill(uint8_t pattern);
void Display_update_screen(void);
void Display_add_intensity(uint8_t delta);
void Display_send_intensity();
uint8_t Display_get_screen(uint8_t **screen_ptr);

#endif /* __DISPLAY_H__ */
