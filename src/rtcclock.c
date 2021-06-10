#include "rtcclock.h"

//TODO:Fix to use unix epoch time (secs from 1970) to extend lifespan

#pragma PERSISTENT(current_time)
time_t current_time = CONFIG_RTC_DEFAULT_START_TIME;


void RealtimeClock_save(time_t new_time)
{
    current_time = new_time;
    FRAMCtl_write32(&new_time, &current_time, (sizeof(time_t) / 4));
}

void RealtimeClock_add(long delta)
{
    unsigned short state;
    ENTER_CRITICAL_SECTION(state);
    time_t new_time = current_time + delta;
    RealtimeClock_save(new_time);
    EXIT_CRITICAL_SECTION(state);
}

void RealtimeClock_init(void) {
    RTC_init(RTC_BASE, CONFIG_RTC_HZ - 1, RTC_CLOCKPREDIVIDER_1);
    RTC_enableInterrupt(RTC_BASE, RTC_OVERFLOW_INTERRUPT);
}

void RealtimeClock_start(void) {
    RTC_start(RTC_BASE, CONFIG_RTC_SOURCE);
}

void RealtimeClock_stop(void) {
    RTC_stop(RTC_BASE);
}

struct tm* RealtimeClock_getCurrentTime(void) {
    unsigned short state;
    ENTER_CRITICAL_SECTION(state);
    struct tm* time = localtime(&current_time);
    EXIT_CRITICAL_SECTION(state);
    return time;
}

void RealtimeClock_setCurrentTime(struct tm *time) {
    unsigned short state;
    ENTER_CRITICAL_SECTION(state);
    time_t new_time = mktime(time);
    RealtimeClock_save(new_time);
    EXIT_CRITICAL_SECTION(state);
}

void RealtimeClock_add_years(long delta)
{
    unsigned short state;
    ENTER_CRITICAL_SECTION(state);
    struct tm *time = RealtimeClock_getCurrentTime();
    time->tm_year += delta;
    if (time->tm_year > MAX_YEAR) {
        time->tm_year = MIN_YEAR;
    } else if (time->tm_year < MIN_YEAR) {
        time->tm_year = MAX_YEAR;
    }
    RealtimeClock_setCurrentTime(time);
    EXIT_CRITICAL_SECTION(state);
}

void RealtimeClock_add_months(long delta)
{
    unsigned short state;
    ENTER_CRITICAL_SECTION(state);
    struct tm *time = RealtimeClock_getCurrentTime();
    time->tm_mon += delta;
    if (time->tm_mon > MAX_MON) {
        time->tm_mon = MIN_MON;
    } else if (time->tm_mon < MIN_MON) {
        time->tm_mon = MAX_MON;
    }
    RealtimeClock_setCurrentTime(time);
    EXIT_CRITICAL_SECTION(state);
}

void RealtimeClock_add_days(long delta)
{
    unsigned short state;
    ENTER_CRITICAL_SECTION(state);
    struct tm *time = RealtimeClock_getCurrentTime();
    int mon = time->tm_mon;
    time->tm_mday += delta;
    if (time->tm_mday > MAX_DAY) {
        time->tm_mday = MIN_DAY;
    } else if (time->tm_mday < MIN_DAY) {
        time->tm_mday = MAX_DAY;
    }
    RealtimeClock_setCurrentTime(time);

    // Guard against transition 28/29/30 -> 1 or vice versa
    time = RealtimeClock_getCurrentTime();
    if (time->tm_mon != mon) {
        time->tm_mon = mon;
        RealtimeClock_setCurrentTime(time);
    }

    EXIT_CRITICAL_SECTION(state);
}

void RealtimeClock_add_hours(long delta)
{
    unsigned short state;
    ENTER_CRITICAL_SECTION(state);
    struct tm *time = RealtimeClock_getCurrentTime();
    time->tm_hour += delta;
    if (time->tm_hour > MAX_HOUR) {
        time->tm_hour = MIN_HOUR;
    } else if (time->tm_hour < MIN_HOUR) {
        time->tm_hour = MAX_HOUR;
    }
    RealtimeClock_setCurrentTime(time);
    EXIT_CRITICAL_SECTION(state);
}

void RealtimeClock_add_minutes(long delta)
{
    unsigned short state;
    ENTER_CRITICAL_SECTION(state);
    struct tm *time = RealtimeClock_getCurrentTime();
    time->tm_min += delta;
    if (time->tm_min > MAX_MIN) {
        time->tm_min = MIN_MIN;
    } else if (time->tm_min < MIN_MIN) {
        time->tm_min = MAX_MIN;
    }
    RealtimeClock_setCurrentTime(time);
    EXIT_CRITICAL_SECTION(state);
}

void RealtimeClock_add_seconds(long delta)
{
    unsigned short state;
    ENTER_CRITICAL_SECTION(state);
    struct tm *time = RealtimeClock_getCurrentTime();
    time->tm_sec += delta;
    if (time->tm_sec > MAX_SEC) {
        time->tm_sec = MIN_SEC;
    } else if (time->tm_sec < MIN_SEC) {
        time->tm_sec = MAX_SEC;
    }
    RealtimeClock_setCurrentTime(time);
    EXIT_CRITICAL_SECTION(state);
}

// RTC interrupt service routine
#pragma vector=RTC_VECTOR
__interrupt void RealtimeClock_isr(void)
{
    RealtimeClock_add(1);
    RTC_clearInterrupt(RTC_BASE, RTC_OVERFLOW_INTERRUPT);
}
