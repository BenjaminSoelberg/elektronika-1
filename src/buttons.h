#ifndef __BUTTONS_H__
#define __BUTTONS_H__

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

#define BUTTONS_POLL_HZ 20
#define BUTTONS_TIMER_BASE TIMER_A1_BASE
#define BUTTONS_TIMER_VECTOR TIMER1_A1_VECTOR

#define BUTTONS_PORT GPIO_PORT_P2
#define BUTTONS_PINS (GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7)


extern void Buttons_init(void);
extern void Buttons_start(void);
extern void Buttons_stop(void);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif /* __BUTTONS_H__ */
