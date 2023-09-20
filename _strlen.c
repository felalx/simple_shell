#include "main.h"

/**
 * _strlen - computes the string length.
 * @l: String
 * Return: On success 'lenght of the string'.
 * On error, -1 is returned.
 */

size_t _strlen(const char *l)
{
	const char *len = l;

	while (*l)
		l++;

	return (l - len);
}
