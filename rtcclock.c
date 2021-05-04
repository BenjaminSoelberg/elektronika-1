#include <msp430.h>
#include <rtcclock.h>
#include <driverlib.h>
#include <time.h>

//TODO:Fix to use unix epoch time (secs from 1970) to extend lifespan

#define START_TIME (1609459200+2208988800) // Fri Jan 01 2021 00:00:00 GMT+0000

#pragma PERSISTENT(rtcclock_current)
time_t rtcclock_current = START_TIME;

struct tm* RTC_getCurrentTime(void) {
    return localtime(&rtcclock_current);
}

// RTC interrupt service routine
#pragma vector=RTC_VECTOR
__interrupt void RTC_ISR(void)
{
    P1OUT ^= BIT1;

    time_t new_rtcclock_current = rtcclock_current + 1;
    FRAMCtl_write32(&new_rtcclock_current, &rtcclock_current, (sizeof(time_t) / 4));

    //__bic_SR_register_on_exit(LPM4_bits);
    RTC_clearInterrupt(RTC_BASE, RTC_OVERFLOW_INTERRUPT);
}
