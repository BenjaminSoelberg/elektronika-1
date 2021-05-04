//#define __TI_TIME32_USES_POSIX_EPOCH


#include <msp430.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "rtcclock.h"

#include "driverlib.h"

volatile unsigned int i = 0;

void blink()
{
    P1DIR |= 00000003;
    for (;;)
    {
        P1OUT ^= 0x01;
        for (i = 0; i < 20000; i++)
            ;
        //printf(asctime(RTC_getCurrentTime()));
    }
}

int main(void)
{
    WDT_A_hold(WDT_A_BASE); // Stop Watchdog Timer

    // #10420-D  For FRAM devices, at start up, the GPIO power-on default high-impedance mode needs to be
    // disabled to activate previously configured port settings. This can be done by clearing the LOCKLPM5
    // bit in PM5CTL0 register
    PM5CTL0 &= ~LOCKLPM5;

    RTC_init(RTC_BASE, 10000 - 1, RTC_CLOCKPREDIVIDER_1);
    RTC_enableInterrupt(RTC_BASE, RTC_OVERFLOW_INTERRUPT);
    RTC_start(RTC_BASE, RTC_CLOCKSOURCE_VLOCLK);

    __bis_SR_register(GIE);

    blink();

    return (0);
}
