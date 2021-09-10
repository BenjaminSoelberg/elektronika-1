#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include "elektronika.h"

#define AS1115_SLAVE_ADDRESS 0x00
#define I2C_BASE EUSCI_B0_BASE
#define CLEAR true
#define NO_CLEAR false

#define SEG_A (0b01000000)
#define SEG_B (0b00100000)
#define SEG_C (0b00010000)
#define SEG_D (0b00001000)
#define SEG_E (0b00000100)
#define SEG_F (0b00000010)
#define SEG_G (0b00000001)
#define SEG_DOT (0b10000000)

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
