#ifndef __RTCCLOCK_H__
#define __RTCCLOCK_H__

#include "elektronika.h"
#include <time.h>

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

extern uint32_t current_time;
extern void RealtimeClock_init(void);
extern void RealtimeClock_start(void);
extern void RealtimeClock_stop(void);

extern struct tm* RealtimeClock_getCurrentTime(void);


//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif /* __RTCCLOCK_H__ */
