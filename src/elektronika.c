#include "elektronika.h"
#include <stdio.h>

#include "clocksystem.h"
#include "rtcclock.h"
#include "buttons.h"
#include "display.h"
#include "render.h"

volatile unsigned int i = 0;


void pre_init(void)
{
    // Stop Watchdog Timer
    WDT_A_hold(WDT_A_BASE);

    //TODO: Seems like prev. port dir and state is set but not in effect while looking at blinking after reset
    PMM_unlockLPM5();

    // Unconnected pins should be set to output mode
    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN7);
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7);
    GPIO_setAsOutputPin(GPIO_PORT_P3, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2);
}

void test_render_current_mm_ss(void)
{
    uint8_t *screen;
    Display_get_screen(&screen);
    struct tm *time = RealtimeClock_getCurrentTime();

    screen[0] = Render_7_segment(time->tm_min / 10, false);
    screen[1] = Render_7_segment(time->tm_min % 10, true);
    screen[2] = Render_7_segment(time->tm_sec / 10, false);
    screen[3] = Render_7_segment(time->tm_sec % 10, false);
}

void render_current_time(void)
{
    uint8_t *screen;
    Display_get_screen(&screen);
    struct tm *time = RealtimeClock_getCurrentTime();

    screen[0] = Render_7_segment_nz(time->tm_hour / 10, false);
    screen[1] = Render_7_segment(time->tm_hour % 10, true);
    screen[2] = Render_7_segment(time->tm_min / 10, false);
    screen[3] = Render_7_segment(time->tm_min % 10, false);
}

void render_current_date(void)
{
    uint8_t *screen;
    Display_get_screen(&screen);
    struct tm *time = RealtimeClock_getCurrentTime();

    screen[0] = Render_7_segment_nz(time->tm_mday / 10, false);
    screen[1] = Render_7_segment(time->tm_mday % 10, false);
    screen[2] = Render_7_segment_nz((time->tm_mon + 1) / 10, false);
    screen[3] = Render_7_segment((time->tm_mon + 1) % 10, false);
}

void render_current_year(void)
{
    uint8_t *screen;
    size_t size = Display_get_screen(&screen);
    struct tm *time = RealtimeClock_getCurrentTime();

    int year = time->tm_year + 1900;
    for (uint8_t i = size; i != 0; i--) {
        screen[i - 1] = Render_7_segment(year % 10, false);
        year /= 10;
    }
}

void handle_time_button(void)
{
    while (Buttons_is_button_down(BUTTON_TIME))
    {
        if (Buttons_is_button_down(BUTTON_SET_H)) {
            Buttons_clear_button(BUTTON_SET_H);
            RealtimeClock_add_hours(1);
        }
        if (Buttons_is_button_down(BUTTON_SET_L)) {
            Buttons_clear_button(BUTTON_SET_L);
            RealtimeClock_add_minutes(1);
        }
        render_current_time();
        Display_update_screen();
    }
}

void handle_date_button(void)
{
    while (Buttons_is_button_down(BUTTON_DATE))
    {
        if (Buttons_is_button_down(BUTTON_SET_H)) {
            Buttons_clear_button(BUTTON_SET_H);
            RealtimeClock_add_days(1);
        }
        if (Buttons_is_button_down(BUTTON_SET_L)) {
            Buttons_clear_button(BUTTON_SET_L);
            RealtimeClock_add_months(1);
        }
        render_current_date();
        Display_update_screen();
    }
}

void handle_year_button(void)
{
    while (Buttons_is_button_down(BUTTON_YEAR))
    {
        if (Buttons_is_button_down(BUTTON_SET_H)) {
            Buttons_clear_button(BUTTON_SET_H);
            RealtimeClock_add_years(1);
        }
        if (Buttons_is_button_down(BUTTON_SET_L)) {
            Buttons_clear_button(BUTTON_SET_L);
            RealtimeClock_add_years(-1);
        }
        render_current_year();
        Display_update_screen();
    }
}

void run(void)
{
    Display_start(CLEAR);

    if (Buttons_is_button_down(BUTTON_TIME)) {
        handle_time_button();
    }
    else if (Buttons_is_button_down(BUTTON_DATE)) {
        handle_date_button();
    }
    else if (Buttons_is_button_down(BUTTON_YEAR)) {
        handle_year_button();
    }

    Display_stop();
}

int main(void)
{
    // Initialize board
    pre_init();

    // Initialize modules
    ClockSystem_init();
    RealtimeClock_init();
    Display_init();
    Buttons_init();

    // Start essential modules
    RealtimeClock_start();
    Buttons_start();

    __enable_interrupt();

    while (true) {
        __low_power_mode_3(); //TODO: How can we see if we enter 3.5 with no buttons pressed ?
        run();
    }
}

