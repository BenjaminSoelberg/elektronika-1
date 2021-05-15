#ifndef __ELEKTRONIKA_H__
#define __ELEKTRONIKA_H__

#include <msp430.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "driverlib.h"
#include "driverlib_ng.h"
#include "config.h"
#include "utils.h"


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
     TA0CCR1: Used by the button driver
     TA0CCR2: Unused
     TA1CCR1: Used by the display driver to multiplex the segments
     TA0CCR2: Used by the display driver to turn off the display when no buttons are pushed for a specified amount of time
 */

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif /* ELEKTRONIKA_H_ */
