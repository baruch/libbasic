#ifndef LIBBASIC_DEFER_H
#define LIBBASIC_DEFER_H

/* This defines a macro that will use a gcc and clang extension to call a
 * cleanup function on a variable at any function exit.
 *
 * Usage:
 *
 * int* data = calloc(sizeof(int), 128);
 * DEFER({ free(data); });
 *
 * This will allocate the memory and will call the free before the scope exit.
 *
 * In unoptimized compilation it will waste a character per defer but in
 * optimized compilation the compiler will eliminate these characters and only
 * call the cleanup function;
 */

#define DEFER_MERGE(a,b) a##b
#define DEFER_VARNAME(a) DEFER_MERGE(defer_scopevar_, a)
#define DEFER_FUNCNAME(a) DEFER_MERGE(defer_scopefunc_, a)
#define DEFER(BLOCK) void DEFER_FUNCNAME(__LINE__)(char *a) BLOCK; __attribute__((cleanup(DEFER_FUNCNAME(__LINE__)))) char DEFER_VARNAME(__LINE__)

#endif
