#include "main.h"
/**
 * main - main function
 * @ac: argument count
 * @av: argument vector
 * Return: On success 1.
 * On error, -1 is returned.
 */

int main(int ac, char **av)
{
	char *lineptr;
	int i;
	char **array;
	size_t n = 0;

	lineptr = NULL;
	handle_args(ac, av);
	while (1)
	{
	if (!read_input_line(&lineptr, &n))
	{
	continue;
	}
	if (lineptr[0] == '^' && lineptr[1] == '[')
	{
	continue;
	}
	array = tokenize_input(lineptr, &i);
	if (!array)
	{
	continue;
	}
	if (check_exit(array))
	{
	free(lineptr);
	exit(0);
	}
	if (_strcmp(array[0], "env") == 0)
	{
	handle_env();
	free(array);
	continue;
	}
	execute_command(array, av[0]);
	free(array);
	}
}
