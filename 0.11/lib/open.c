/*
 *  linux/lib/open.c
 *
 *  (C) 1991  Linus Torvalds
 */

#define __LIBRARY__
#include <unistd.h>
#include <stdarg.h>

int open(const char * filename, int flag, ...)
{
	register int res;
	va_list arg;
	
	va_start(arg,flag);
	// use va_start to store args after flags into arg
	// open file
	// %0 - eax(ret descriptor or err code)；%1 - eax(sys int nr: __NR_open)；
	// %2 - ebx(filename)；%3 - ecx(flag)；%4 - edx(mode)。 
	__asm__("int $0x80"
		:"=a" (res)
		:"0" (__NR_open),"b" (filename),"c" (flag),
		"d" (va_arg(arg,int)));
	if (res>=0)				// descriptor
		return res;
	errno = -res;			// error
	return -1;
}
