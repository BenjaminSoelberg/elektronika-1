#ifndef __BUTTONS_H__
#define __BUTTONS_H__

#include "elektronika.h"

#define BUTTONS_POLL_HZ 30 /* (1/30*3) 100ms minimal response time. Worst case (1/30*7) 233ms if debounce takes longer than (1/30) 3.33ms. See MASK. */
#define BUTTONS_TIMER_BASE TIMER_A1_BASE
#define BUTTONS_TIMER_VECTOR TIMER1_A1_VECTOR
#define IGNORE_BUTTON -1

#ifdef USE_LAUNCHPAD
#define BUTTONS_PORT GPIO_PORT_P2
#define BUTTON_PINS (GPIO_PIN3 | GPIO_PIN7)
typedef enum
{
    BUTTON_YEAR = 1,
    BUTTON_DATE = IGNORE_BUTTON,
    BUTTON_SET_H = IGNORE_BUTTON,
    BUTTON_SET_L = IGNORE_BUTTON,
    BUTTON_TIME = 0
} BUTTONS;
#else
#define BUTTONS_PORT GPIO_PORT_P1
#define BUTTON_PINS (GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6)
typedef enum
{
    BUTTON_YEAR = 0,
    BUTTON_DATE = 1,
    BUTTON_SET_H = 2,
    BUTTON_SET_L = 3,
    BUTTON_TIME = 4
} BUTTONS;
#endif

void Buttons_init(void);
void Buttons_start(void);
void Buttons_stop(void);
void Buttons_timer_stop(void);

bool Buttons_is_button_up(BUTTONS button);
bool Buttons_is_button_down(BUTTONS button);
bool Buttons_is_button_pressed(BUTTONS button);
bool Buttons_is_button_released(BUTTONS button);
void Buttons_clear_button(BUTTONS button);

#endif /* __BUTTONS_H__ */
