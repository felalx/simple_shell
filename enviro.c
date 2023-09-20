#include "main.h"

/**
 * handle_env - Handle environment.
 *
 * Return: On success void.
 * On error: -1 is returned.
 */

void handle_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
	}
}
