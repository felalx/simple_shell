#include "main.h"

/**
 * handle_args - handle arguments.
 * @ac: argument count
 * @av: argument vector
 * Return: On success void.
 * On error: -1 is returned.
 */

void handle_args(int ac, char **av)
{
	int i;

	for (i = 1; i < ac; i++)
	{
		_printf("Received argument: %s\n", av[i]);
	}
}

