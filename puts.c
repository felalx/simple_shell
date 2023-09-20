#include "main.h"

/**
 * _puts - writes the string c to stdout
 * @str: String format.
 *
 * Return: On success 1.
 * On error, -1 is returned.
 */

int _puts(const char *str)
{
	while (*str)
	{
		if (_putchar(*str) == EOF)
		{
			return (EOF);
		}
		str++;
	}

	if (_putchar('\n') == EOF)
	{
		return (EOF);
	}

	return (1);
}
