#include "main.h"

/**
 * _printf -This function produces output according to a format 
 * @format: is a character string the format string 
 * consists of azero or more directives 
 * 
 * return: Number of characters printed(this excludes 
 * the null byte used to end output to strings )
**/
int _printf(const char *format, ...){
	int size;
	va_list args;

	if (format == NULL)
	return(-1);
	size = _strlen(format);
	if (size <= 0 ) 
	return (0);

	va_start(args, format);
	size = handler(format, args);

	_putchar(-1);
	va_end(args);

	return (size )

}