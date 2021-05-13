#ifndef __TIMER_H__
#define __TIMER_H__

#include "elektronika.h"

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C" {
#endif

extern void Timer_A_startContinuousTimer(uint16_t baseAddress);

extern void Timer_A_stopContinuousTimer(uint16_t baseAddress);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif /* __TIMER_H__ */
