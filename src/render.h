#ifndef __RENDER_H__
#define __RENDER_H__

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

extern uint8_t Render_7_segment(uint8_t ch, bool dp);
extern uint8_t Render_7_segment_nz(uint8_t ch, bool dp);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif /* __RENDER_H__ */
