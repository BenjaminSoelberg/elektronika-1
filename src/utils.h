#ifndef __UTILS_H__
#define __UTILS_H__

#define st(x)                       do { x } while (__LINE__ == -1)
#define ENTER_CRITICAL_SECTION(x)   st( x = __get_SR_register(); __disable_interrupt(); )
#define EXIT_CRITICAL_SECTION(x)    __set_interrupt_state(x)

#endif /* __UTILS_H__ */
