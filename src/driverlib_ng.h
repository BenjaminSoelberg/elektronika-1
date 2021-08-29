#ifndef __DRIVERLIB_NG_H__
#define __DRIVERLIB_NG_H__

#include "driverlib.h"

uint8_t GPIO_getInputPinValues(uint8_t selectedPort, uint8_t selectedPins);
void GPIO_setOutputPinsOnPort(uint8_t selectedPort, uint8_t pinValues);

#endif /* __DRIVERLIB_NG_H__ */
