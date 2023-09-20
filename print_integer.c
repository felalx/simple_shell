#include "main.h"

/**
 * print_integer - Prints integer
 * @args: Arguments
 * Return: On success void.
 * On error, -1 is returned.
 */

void print_integer(va_list args)
{
	char *ptr;
	int num;
	char buffer[12];

	num = va_arg(args, int);
	if (num == 0)
	{
		_putchar('0');
		return;
	}

	_snprintf(buffer, sizeof(buffer), "%d", num);

	for (ptr = buffer; *ptr; ptr++)
	{
		_putchar(*ptr);
	}
}
