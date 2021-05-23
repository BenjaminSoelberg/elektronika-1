#include "elektronika.h"

#include "clocksystem.h"
#include "rtcclock.h"
#include "buttons.h"
#include "display.h"

volatile unsigned int i = 0;

int main(void)
{
    WDT_A_hold(WDT_A_BASE); // Stop Watchdog Timer

    PMM_unlockLPM5(); //TODO: Seems like prev. port dir and state is set but not in effect while looking at blinking after reset

    CS_init();

    RealtimeClock_init();
    Buttons_init();
    Display_init();

    RealtimeClock_start();
    Buttons_start();

    //TODO Just a test
    uint8_t display[] = {1, 3+0x80, 4, 7};
    Display_update((uint8_t*)&display);
    Display_start();

    __enable_interrupt();

    while (true) {
        __low_power_mode_3();//TODO: How can we see if we enter 3.5 with no buttons pressed ?
    }
}
