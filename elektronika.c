#include "elektronika.h"

#include "rtcclock.h"
#include "buttons.h"
#include "display.h"

volatile unsigned int i = 0;

void blink()
{
    P1DIR |= 0x01;
    P1OUT ^= 0x01;

    for (int i = 0; i < 100; i++) {
        __no_operation();
    }
}

//TODO: Look at clock system to enable lpm 3.5 (only rtc) and lpm3 (before display timeout and entering lpm 3.5)
int main(void)
{
    WDT_A_hold(WDT_A_BASE); // Stop Watchdog Timer

    PMM_unlockLPM5(); //TODO:Seems like prev. port dir and state is set but not in effect while looking at blinking after reset

    //CS_turnOnXT1LF ??
    //CS_setExternalClockSource ??

    // What if MCLK could be running on the 32khz crystal... this might save a lot of power.
    // Also MCLK could be set to a faster clock while the display is on ??
    //CS_initClockSignal(CS_MCLK, CONFIG_LFO_SOURCE, CS_CLOCK_DIVIDER_1);

    CS_initClockSignal(CS_ACLK, CONFIG_LFO_SOURCE, CS_CLOCK_DIVIDER_1);
    // TODO Look into what clocks can be off CS_turnOffSMCLK();
    // TODO Look into what clocks can be off CS_enableClockRequest(ACLKREQEN);

    RealtimeClock_init();
    Buttons_init();
    Display_init();

    RealtimeClock_start();
    Buttons_start();
    //Display_start();

    __enable_interrupt();

    while (true) {
        __low_power_mode_3();
//        blink();
    }

    //return (0);
}
