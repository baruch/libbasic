#ifndef LIBBASIC_H
#define LIBBASIC_H

#define __tostr(x) #x
#define STR(x) __tostr(x)

#define likely(expr)    __builtin_expect((expr) != 0, 1)
#define unlikely(expr)  __builtin_expect((expr) != 0, 0)

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

#ifdef __GNUC
#define UNUSED(x) UNUSED_ ## x __attribute__((__unused__))
#else
#define UNUSED(x) UNUSED_ ## x
#endif

int sock_set_nonblock(int sock);
int sock_set_reuse(int sock);

#endif
