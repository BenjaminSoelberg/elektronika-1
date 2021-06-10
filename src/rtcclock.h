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

#define MIN_YEAR (2020-1900)
#define MAX_YEAR (2035-1900)

#define MIN_MON 0
#define MAX_MON 11

#define MIN_DAY 1
#define MAX_DAY 31

#define MIN_HOUR 0
#define MAX_HOUR 23

#define MIN_MIN 0
#define MAX_MIN 59

#define MIN_SEC 0
#define MAX_SEC 59

extern uint32_t current_time;
extern void RealtimeClock_init(void);
extern void RealtimeClock_start(void);
extern void RealtimeClock_stop(void);
extern struct tm* RealtimeClock_getCurrentTime(void);
extern void RealtimeClock_setCurrentTime(struct tm *time);
extern void RealtimeClock_add(long delta);
extern void RealtimeClock_add_years(long delta);
extern void RealtimeClock_add_months(long delta);
extern void RealtimeClock_add_days(long delta);
extern void RealtimeClock_add_hours(long delta);
extern void RealtimeClock_add_minutes(long delta);
extern void RealtimeClock_add_secounds(long delta);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif /* __RTCCLOCK_H__ */
