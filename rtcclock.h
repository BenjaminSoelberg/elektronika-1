#ifndef RTCCLOCK_H_TXT_
#define RTCCLOCK_H_TXT_

#include <stdint.h>

/* The user may access the current clock timestamp directly instead of using RTClock_get().
 *
 * However, if you expect to perform multiple operations (comparisons, say) against it in a single
 * block of code, it might be useful to make a copy of this into a local variable first, as the counter
 * is liable to change at any time based on when the RTC interrupt fires.
 */
extern uint32_t rtcclock_current;

extern struct tm* RTC_getCurrentTime(void);

#endif /* RTCCLOCK_H_TXT_ */
