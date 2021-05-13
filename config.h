/*
 * config.h
 *
 *  Created on: May 9, 2021
 *      Author: user
 */

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

/* HARDWARE TIMER ASSIGNMENT:
     Timer0_A3: Used by the display driver to multiplex the segments
     Timer1_A3: Used to turn off the display when no buttons are pushed for a specified amount of time
     Timer2_A2: Used by the button driver
     Timer3_A2: Unused
 */

#define CONFIG_LFO_SOURCE  CS_REFOCLK_SELECT
#define CONFIG_LFO_HZ      32768
#define CONFIG_RTC_SOURCE  RTC_CLOCKSOURCE_VLOCLK
#define CONFIG_RTC_HZ      10000

//#define CONFIG_RTC_BLINK_ALIVE
//#define CONFIG_DISPLAY_BLINK_ALIVE
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
