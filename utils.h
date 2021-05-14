#ifndef __UTILS_H__
#define __UTILS_H__

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

#define st(x)                       do { x } while (__LINE__ == -1)
#define ENTER_CRITICAL_SECTION(x)   st( x = __get_SR_register(); __disable_interrupt(); )
#define EXIT_CRITICAL_SECTION(x)    __set_interrupt_state(x)

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif /* __UTILS_H__ */
