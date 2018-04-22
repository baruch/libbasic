#ifndef LIBBASIC_H
#define LIBBASIC_H

#include <stddef.h> // for offsetof

#ifndef STR
#define __tostr(x) #x
#define STR(x) __tostr(x)
#endif

#ifndef likely
#define likely(expr)    __builtin_expect((expr) != 0, 1)
#endif

#ifndef unlikely
#define unlikely(expr)  __builtin_expect((expr) != 0, 0)
#endif

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#endif

#ifndef container_of
#define container_of(ptr, type, member) \
	({ \
		const typeof( ((type*)0)->member ) \
		* __mptr = ((void*)(ptr)); \
		(type*)( (char*)__mptr - \
		offsetof(type, member) ); \
	})
#endif

#ifndef MIN
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#endif

#ifndef MAX
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#endif

#ifndef UNUSED
#ifdef __GNUC
#define UNUSED(x) UNUSED_ ## x __attribute__((__unused__))
#else
#define UNUSED(x) UNUSED_ ## x
#endif
#endif

int sock_set_nonblock(int sock);
int sock_set_reuse(int sock);

#endif
