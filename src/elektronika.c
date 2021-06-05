#include "elektronika.h"

#include "clocksystem.h"
#include "rtcclock.h"
#include "buttons.h"
#include "display.h"

volatile unsigned int i = 0;

//#define HAS_AS1115

void init(void)
{
    // Stop Watchdog Timer
    WDT_A_hold(WDT_A_BASE);

    //TODO: Seems like prev. port dir and state is set but not in effect while looking at blinking after reset
    PMM_unlockLPM5();

    // Unconnected pins should be set to output mode (they are also available as test points on the board)
    GPIO_setAsOutputPin(GPIO_PORT_P1, BIT7);
    GPIO_setAsOutputPin(GPIO_PORT_P2, BIT2 | BIT3 | BIT4 | BIT7);
    GPIO_setAsOutputPin(GPIO_PORT_P3, BIT0 | BIT1 | BIT2);
}

int main(void)
{
    init();

    // Initialize modules
    ClockSystem_init();
    RealtimeClock_init();
#ifdef HAS_AS1115
    Display_init();
#endif
    Buttons_init();

    // Start essential modules
    RealtimeClock_start();
    Buttons_start();

#ifdef HAS_AS1115
    uint8_t display[] = { 1, 3 + 0x80, 4, 7 };
    Display_update((uint8_t*) &display);
    Display_start();
#endif

    __enable_interrupt();

    while (true) {
//        __low_power_mode_3(); //TODO: How can we see if we enter 3.5 with no buttons pressed ?
        if (Buttons_is_button_down(BUTTON_SET_H)) {
                GPIO_setAsOutputPin(GPIO_PORT_P1, BIT0);
                GPIO_toggleOutputOnPin(GPIO_PORT_P1, BIT0);
                //__no_operation();
        }
    }
}

