#ifndef __RTCCLOCK_H__
#define __RTCCLOCK_H__

#include "elektronika.h"
#include <time.h>

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
void RealtimeClock_init(void);
void RealtimeClock_start(void);
void RealtimeClock_stop(void);
struct tm* RealtimeClock_getCurrentTime(void);
void RealtimeClock_setCurrentTime(struct tm *time);
void RealtimeClock_add(long delta);
void RealtimeClock_add_years(long delta);
void RealtimeClock_add_months(long delta);
void RealtimeClock_add_days(long delta);
void RealtimeClock_add_hours(long delta);
void RealtimeClock_add_minutes(long delta);
void RealtimeClock_add_secounds(long delta);

#endif /* __RTCCLOCK_H__ */
