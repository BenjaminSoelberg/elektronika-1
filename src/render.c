#include "render.h"

uint8_t Render_7_segment(uint8_t ch, bool dp)
{
#ifndef HAS_AS1115
    return ch+48;
#else
    uint8_t result;
    switch (ch)
    {
    case 0:
        result = 0b01111110;
        break;
    case 1:
        result = 0b00110000;
        break;
    case 2:
        result = 0b01101101;
        break;
    case 3:
        result = 0b01111001;
        break;
    case 4:
        result = 0b00110011;
        break;
    case 5:
        result = 0b01011011;
        break;
    case 6:
        result = 0b01011111;
        break;
    case 7:
        result = 0b01110000;
        break;
    case 8:
        result = 0b01111111;
        break;
    case 9:
        result = 0b01111011;
        break;
    default:
        result = 0b01001001;
        break;
    }

    if (dp) {
        result |= 0b10000000;
    }

    return result;
#endif
}

uint8_t Render_7_segment_nz(uint8_t ch, bool dp)
{
#ifndef HAS_AS1115
    if (ch == 0) {
        return ' ';
    }
    return Render_7_segment(ch, dp);
#else
    if (ch == 0) {
        if (dp) {
            return 0b10000000;
        }
        return 0;
    }

    return Render_7_segment(ch, dp);
#endif
}
