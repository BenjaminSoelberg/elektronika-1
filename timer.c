#include "timer.h"
#include "timer_a.h"

void Timer_A_startContinuousTimer(uint16_t baseAddress)
{
    HWREG16(baseAddress + OFS_TAxCTL) |= TIMER_A_CONTINUOUS_MODE;
}

void Timer_A_stopContinuousTimer(uint16_t baseAddress)
{
    HWREG16(baseAddress + OFS_TAxCTL) &= ~TIMER_A_CONTINUOUS_MODE;
}


//TODO: C AND H FILE CAN BE DELETED!!!
