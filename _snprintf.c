#include "main.h"
/**
 * _snprintf - prints formated string to buffer
 * @format: buffer
 * @size: buffer size,
 * @str: string input,
 * Return: On success void.
 */
int _snprintf(char *str, size_t size, const char *format, ...)
{
	va_list args;
	int out = 0;
	const char *ptr;

	va_start(args, format);
	for (ptr = format; *ptr && (size - out - 1) > 0; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			switch (*ptr)
			{
				case 's':
					out += append(str + out, size - out, va_arg(args, char*));
					break;
				case 'd':
					out += append_int(str + out, size - out, va_arg(args, int));
					break;
				case '%':
					str[out++] = '%';
					break;
				default:
					str[out++] = '%';
					str[out++] = *ptr;
					break;
			}
		}
		else
			str[out++] = *ptr;
	}
	str[out] = '\0';
	va_end(args);
	return (out);
}
