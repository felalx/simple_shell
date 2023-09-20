#include "shell.h"

/**
 * print_prompt - this prints the prompt to standard output
 * @prompt: this is the prompt to be printed
 *
 * Return: it returns 0 in interactive mode and 1 in non interactive mode
 */
int print_prompt(char *prompt)
{
	if (isatty(0))
		_fputstr(1, prompt);

	return (0);
}
