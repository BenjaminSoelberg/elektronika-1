#ifndef __DISPLAY_H__
#define __DISPLAY_H__

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

#define AS1115_SLAVE_ADDRESS 0x00
#define I2C_BASE EUSCI_B0_BASE

void Display_init(void);
void Display_start(void);
void Display_stop(void);
void Display_update_screen(void);
void Display_set_intensity(uint8_t intensity);
uint8_t Display_get_screen(uint8_t **screen_ptr);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif /* __DISPLAY_H__ */
