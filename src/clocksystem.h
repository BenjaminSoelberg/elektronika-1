#ifndef __CLOCKSYSTEM_H__
#define __CLOCKSYSTEM_H__

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

extern void ClockSystem_init(void);
extern void ClockSystem_start(void);
extern void ClockSystem_stop(void);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif /* __CLOCKSYSTEM_H__ */
