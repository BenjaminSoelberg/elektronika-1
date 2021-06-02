#ifndef __BUTTONS_H__
#define __BUTTONS_H__

#include "elektronika.h"

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

#define USE_LAUNCHPAD

#define BUTTONS_POLL_HZ 20 /* (1/20*3) 150ms minimal response time. Worst case (1/20*8) 400ms if debounce takes longer than (1/20) 5ms. See MASK. */
#define BUTTONS_TIMER_BASE TIMER_A1_BASE
#define BUTTONS_TIMER_VECTOR TIMER1_A1_VECTOR

#ifdef USE_LAUNCHPAD
#define BUTTONS_PORT GPIO_PORT_P2
#define BUTTON_PINS (GPIO_PIN3 | GPIO_PIN7)
typedef enum
{
    BUTTON_SEC = -1,
    BUTTON_DATE = 0,
    BUTTON_SET_H = 1,
    BUTTON_SET_L = -1,
    BUTTON_TIME = -1
} BUTTONS;
#else
#define BUTTONS_PORT GPIO_PORT_P1
#define BUTTON_PINS (GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6)
enum BUTTONS
{
    SEC = 0,
    DATE = 1,
    SET_H = 2,
    SET_L = 3,
    TIME = 4
};
#endif

extern void Buttons_init(void);
extern void Buttons_start(void);
extern void Buttons_stop(void);
extern void Buttons_timer_stop(void);

extern bool Buttons_is_button_up(BUTTONS button);
extern bool Buttons_is_button_down(BUTTONS button);
extern bool Buttons_is_button_pressed(BUTTONS button);
extern bool Buttons_is_button_released(BUTTONS button);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif /* __BUTTONS_H__ */