#include "main.h"

/**
 * execute_command - Command execution
 * @array: Array of command and arguments
 * @program_name: Name of the program
 * Return: On success void.
 * On error, -1 is returned.
 */

void execute_command(char **array, char *program_name)
{
	pid_t child_pid;
	int status;
	char *full_path;

	if (array[0][0] == '/')
	{
		full_path = _strdup(array[0]);
	}
	else
	{
	full_path = find_command_in_path(array[0]);
	if (!full_path)
	{
	if (array[0][0] == '\033')
	{
	_printf("%s: No such file or directory\n", program_name);
	}
	else
	{
	_printf("%s: %s: No such file or directory\n", program_name, array[0]);
	}
	return;
	}
	}

	child_pid = fork();
	if (child_pid == 0)
	{
	if (execve(full_path, array, NULL) == -1)
	{
	_printf("%s: %s: No such file or directory\n", program_name, array[0]);
	free(full_path);
	exit(EXIT_FAILURE);
	}
	}
	else
	{
	wait(&status);
	}
	free(full_path);
}

