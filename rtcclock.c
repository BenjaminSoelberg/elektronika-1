#include "rtcclock.h"

//TODO:Fix to use unix epoch time (secs from 1970) to extend lifespan

#pragma PERSISTENT(current_time)
time_t current_time = CONFIG_RTC_DEFAULT_START_TIME;


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
    return localtime(&current_time);
}

// RTC interrupt service routine
#pragma vector=RTC_VECTOR
__interrupt void RealtimeClock_isr(void)
{
#ifdef CONFIG_RTC_BLINK_ALIVE
    P1DIR |= 0x02;
    P1OUT ^= 0x02;
#endif

    time_t new_current_time = current_time + 1;
    FRAMCtl_write32(&new_current_time, &current_time, (sizeof(time_t) / 4));

    RTC_clearInterrupt(RTC_BASE, RTC_OVERFLOW_INTERRUPT);
}
