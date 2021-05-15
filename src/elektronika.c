#include "elektronika.h"

#include "rtcclock.h"
#include "buttons.h"
#include "display.h"

volatile unsigned int i = 0;

int main(void)
{
    WDT_A_hold(WDT_A_BASE); // Stop Watchdog Timer

    PMM_unlockLPM5(); //TODO: Seems like prev. port dir and state is set but not in effect while looking at blinking after reset

    // Route P2.0 and P2.1 to XT_LF, start the oscillator and source ACLK as well
    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P2, GPIO_PIN0 | GPIO_PIN1, GPIO_PRIMARY_MODULE_FUNCTION);
    CS_setExternalClockSource(CONFIG_LFO_HZ);
    CS_turnOnXT1LF(CS_XT1_DRIVE_0);
    CS_initClockSignal(CS_ACLK, CONFIG_LFO_SOURCE, CS_CLOCK_DIVIDER_1);

    //TODO: enable this for extra power save... but will the display driver have enough time... test it!
    //CS_initClockSignal(CS_MCLK, CONFIG_LFO_SOURCE, CS_CLOCK_DIVIDER_1);
    //TODO: Look into what clocks can be off CS_turnOffSMCLK();

    RealtimeClock_init();
    Buttons_init();
    Display_init();

    RealtimeClock_start();
    Buttons_start();

    //TODO Just a test
    uint8_t display[] = {1, 2, 7, 0x80};
    Display_update((uint8_t*)&display);
    Display_start();

    __enable_interrupt();

    while (true) {
        __low_power_mode_3();//TODO: Test to see if we enter 3.5 with no buttons pressed
    }
}
