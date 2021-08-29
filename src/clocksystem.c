#include "clocksystem.h"

void ClockSystem_init(void)
{
    // Route P2.0 and P2.1 to XT_LF, start the oscillator and source ACLK as well
    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P2, GPIO_PIN0 | GPIO_PIN1, GPIO_PRIMARY_MODULE_FUNCTION);
    CS_setExternalClockSource(CONFIG_LFO_HZ);
    // TODO: The configuration of these bits is retained during LPM3.5 until LOCKLPM5 is cleared,
    // TODO: but not the register bits itself; therefore, reconfiguration is required after
    // TODO: wakeup from LPM3.5 and before clearing LOCKLPM5.
    // TODO: What else is reset upon wakeup from LPM3.5 ???

    CS_turnOnXT1LF(CS_XT1_DRIVE_2); // Use CC7V-T1A-32.768kHz-12.5pF-20PPM-TA-QC. See slaa367
    CS_initClockSignal(CS_ACLK, CONFIG_LFO_SOURCE, CS_CLOCK_DIVIDER_1);
    CS_enableClockRequest(CS_MODOSC);
    //TODO: enable this for extra power save... but will the display driver have enough time... test it!
    //CS_initClockSignal(CS_MCLK, CONFIG_LFO_SOURCE, CS_CLOCK_DIVIDER_1);
    //TODO: Look into what clocks can be off CS_turnOffSMCLK();
}
