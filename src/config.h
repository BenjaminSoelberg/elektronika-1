#ifndef __CONFIG_H__
#define __CONFIG_H__

#define CONFIG_LFO_SOURCE  CS_XT1CLK_SELECT
#define CONFIG_LFO_HZ      32768

#define CONFIG_RTC_SOURCE  RTC_CLOCKSOURCE_XT1CLK
#define CONFIG_RTC_HZ      32768
#define CONFIG_RTC_DEFAULT_START_TIME (1631400985 + 2208988800) // Saturday, September 11, 2021 22:56:25
#define CONFIG_OSCMOD_HZ   5000000

#endif /* __CONFIG_H__ */
