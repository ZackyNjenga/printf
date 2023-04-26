#include "main.h"
int _printf(const char *format, ...) {
  va_list args;
  int count = 0;

  va_start(args, format);
  while (*format != '\0') {
    if (*format == '%') {
      switch (*++format) {
        case 'c': {
          char c = va_arg(args, int);
          putchar(c);
          count++;
          break;
        }
        case 's': {
          char *s = va_arg(args, char *);
          fputs(s, stdout);
          count += strlen(s);
          break;
        }
        case '%': {
          putchar('%');
          count++;
          break;
        }
        case 'd': {
          int d = va_arg(args, int);
          printf("%d", d);
          count += 1 + log10(d);
          break;
        }
        case 'i': {
          int i = va_arg(args, int);
          printf("%d", i);
          count += 1 + log10(i);
          break;
        }
        default: {
          // This is an unrecognized format specifier.
          return -1;
        }
      }
    } else {
      putchar(*format);
      count++;
    }
    format++;
  }

  va_end(args);

  return count;
}
