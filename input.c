#include "main.h"

/**
 * read_input_line - Reads from standard input
 * @lineptr: buffer
 * @n: string length
 * Return: On success void.
 * On error, -1 is returned.
 */

char *read_input_line(char **lineptr, size_t *n)
{
	ssize_t read_status;

	if (isatty(STDIN_FILENO) && write(1, "($) ", 4) == -1)
	{
		perror("Error:");
	}

	read_status = getline(lineptr, n, stdin);
	if (read_status == -1)
	{
		free(lineptr);
		if (!isatty(STDIN_FILENO))
		{
			exit(0);
		}

		if (errno)
		{
			perror("Error");
		}
		exit(0);
	}
	return (*lineptr);
}


/**
 * tokenize_input - To tokenize the inputs
 * @line: Read line
 * @size: Size to read
 * Return: On success array.
 * On error, -1 is returned.
 */


char **tokenize_input(char *line, int *size)
{
	char *token;
	int i = 0;
	char **array = malloc(sizeof(char *) * 1024);

	if (!array)
	{
		free(array);
		perror("Error allocating memory");
		return (NULL);
	}

	token = strtok(line, " \t\n");
	while (token)
	{
		array[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	array[i] = NULL;
	*size = i;

	return (array);
}

