#include "main.h"

/**
 * pr_str - Prints string
 * @args: arguments
 * Return: On success void.
 * On error: -1 is returned.
 */

void pr_str(va_list args)
{
	const char *str;

	str = va_arg(args, const char *);
	while (*str)
	{
		_putchar(*str);
		str++;
	}
}
