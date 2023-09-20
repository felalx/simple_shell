#include "main.h"

/**
 * print_int - To print integer format specifier
 * @value: Integer format
 * Return: On success integer.
 * On error: -1 is returned.
 */

void print_int(int value)
{
	char buffer[20];
	int i = 0;
	int j;

	if (value == 0)
	{
		_putchar('0');
		return;
	}

	if (value < 0)
	{
		_putchar('-');
		value = -value;
	}

	while (value)
	{
		buffer[i++] = '0' + (value % 10);
		value /= 10;
	}

	for (j = i - 1; j >= 0; j--)
	{
		_putchar(buffer[j]);
	}
}
