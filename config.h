#ifndef __CONFIG_H__
#define __CONFIG_H__

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

#define CONFIG_LFO_SOURCE  CS_REFOCLK_SELECT
#define CONFIG_LFO_HZ      32768
#define CONFIG_RTC_SOURCE  RTC_CLOCKSOURCE_VLOCLK
#define CONFIG_RTC_HZ      10000

//#define CONFIG_RTC_BLINK_ALIVE
#define CONFIG_BUTTONS_TIMER_BLINK_ALIVE
#define CONFIG_BUTTONS_PRESSED_BLINK_ALIVE

#define CONFIG_RTC_DEFAULT_START_TIME (1609459200+2208988800) // Fri Jan 01 2021 00:00:00 GMT+0000

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif /* __CONFIG_H__ */
