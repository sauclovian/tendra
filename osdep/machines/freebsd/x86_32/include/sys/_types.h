#ifndef __HACKED_SYS__TYPES_H
#define __HACKED_SYS__TYPES_H

#if defined(_FREEBSD10_4)
#define __aligned(x)
#endif

#include_next <sys/_types.h>

#endif
