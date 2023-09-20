#include "main.h"

/**
 * _*find_command_in_path - check PATH
 * @command: Command to find
 * Return: On success NULL.
 * On error, -1 is returned.
 */

char *find_command_in_path(const char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *token = strtok(path_copy, ":");
	char *full_path = malloc(1024);

	if (!full_path)
	{
		perror("Error allocating memory for full_path");
		free(path_copy);
		return (NULL);
	}

	while (token)
	{
		_snprintf(full_path, 1024, "%s/%s", token, command);
		if (access(full_path, F_OK) != -1)
		{
			free(path_copy);
			return (full_path);
		}
		token = strtok(NULL, ":");
	}

	free(path_copy);
	free(full_path);
	return (NULL);
}

