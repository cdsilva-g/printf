#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
int _putchar(char c);
int _printf(const char *format, ...);
int printf_char(va_list list);
int printf_str(va_list list);
#endif /*end of MAIN_H */
