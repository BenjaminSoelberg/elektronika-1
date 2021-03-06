#ifndef __BUTTONS_H__
#define __BUTTONS_H__

#include "elektronika.h"

#define BUTTONS_POLL_HZ 30 /* (1/30*3) 100ms minimal response time. Worst case (1/30*7) 233ms if debounce takes longer than (1/30) 3.33ms. See MASK. */
#define BUTTONS_TIMER_BASE TIMER_A1_BASE
#define BUTTONS_TIMER_VECTOR TIMER1_A1_VECTOR

#define BUTTONS_PORT GPIO_PORT_P1
#define BUTTON_PINS (GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6)
#define BUTTONS_VECTOR PORT1_VECTOR
typedef enum
{
    BUTTON_TIME = 1,
    BUTTON_SET_H = 4,
    BUTTON_SET_L = 3,
    BUTTON_DATE = 2,
    BUTTON_YEAR = 0,
} BUTTONS;

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
