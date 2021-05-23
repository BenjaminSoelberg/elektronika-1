#include "clocksystem.h"

void CS_init(void)
{
    // Route P2.0 and P2.1 to XT_LF, start the oscillator and source ACLK as well
    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P2, GPIO_PIN0 | GPIO_PIN1, GPIO_PRIMARY_MODULE_FUNCTION);
    CS_setExternalClockSource(CONFIG_LFO_HZ);
    CS_turnOnXT1LF(CS_XT1_DRIVE_0);
    CS_initClockSignal(CS_ACLK, CONFIG_LFO_SOURCE, CS_CLOCK_DIVIDER_1);

    //TODO: enable this for extra power save... but will the display driver have enough time... test it!
    //CS_initClockSignal(CS_MCLK, CONFIG_LFO_SOURCE, CS_CLOCK_DIVIDER_1);
    //TODO: Look into what clocks can be off CS_turnOffSMCLK();
}

void CS_start(void)
{
}

void CS_stop(void)
{
}
