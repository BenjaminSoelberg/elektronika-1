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

#define DISPLAY_TIMER_BASE TIMER_A0_BASE
#define DISPLAY_TIMER_VECTOR TIMER0_A1_VECTOR
#define DISPLAY_MULTIPLEX_HZ 100

extern void Display_init(void);
extern void Display_start(void);
extern void Display_stop(void);
extern void Display_update(uint8_t *data);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif /* __DISPLAY_H__ */
