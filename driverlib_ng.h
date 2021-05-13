#ifndef __DRIVERLIB_NG_H__
#define __DRIVERLIB_NG_H__

#include "driverlib.h"

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

extern uint16_t GPIO_getInputPinValues(uint8_t selectedPort, uint16_t selectedPins);

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

#endif /* __DRIVERLIB_NG_H__ */
