#include "main.h"

/**
 * _printf - writes the string c to stdout.
 * @format: String format
 * Return: On success void.
 * On error, -1 is returned.
 */

void _printf(const char *format, ...)
{
	const char *p;
	va_list args;

	va_start(args, format);

	for (p = format; *p != '\0'; p++)
	{
		if (*p != '%')
		{
			_putchar(*p);
			continue;
		}
		p++;
		switch (*p)
		{
			case 's':
				pr_str(args);
				break;
			case 'd':
				print_integer(args);
				break;
			case '%':
				_putchar('%');
				break;
		}
	}

	va_end(args);
}

