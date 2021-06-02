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

extern void Display_init(void);
extern void Display_start(void);
extern void Display_stop(void);
extern void Display_update(uint8_t *data);
extern void Display_set_intensity(uint8_t intensity);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif /* __DISPLAY_H__ */
