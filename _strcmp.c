#include "main.h"

/**
 * _strdup - duplicates string
 * @src: string to be duplicated.
 * Return: On success duplicate.
 * On error, -1 is returned.
 */

char *_strdup(const char *src)
{
	char *duplicate;
	char *temp;

	if (src == NULL)
	{
		return (NULL);
	}

	duplicate = (char *)malloc(strlen(src) + 1);
	if (duplicate == NULL)
	{
		return (NULL);
	}

	temp = duplicate;
	while ((*temp++ = *src++))
		;

	return (duplicate);
}
