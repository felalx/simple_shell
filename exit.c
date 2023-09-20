#include "main.h"

/**
 * check_exit - To check exit command
 * @array: String to compare with exit command
 * Return: On success 0.
 * On error, -1 is returned.
 */

int check_exit(char **array)
{
	if (_strcmp(array[0], "exit") == 0)
	{
		free(array);
		return (1);
	}
	return (0);
}
