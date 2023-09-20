#include "main.h"

/**
 * append - appends to buffer.
 * @buf: Buffer
 * @size: size
 * @src: char value
 * Return: On success void append(); On error 0
 */

int append(char *buf, size_t size, const char *src)
{
	int written = 0;

	while (*src && (size - written - 1) > 0)
	{
		*buf++ = *src++;
		written++;
	}

	*buf = '\0';
	return (written);
}

/**
 * append_int - appent value
 * @buf: buffer pointer
 * @size: len
 * @value: value
 *Return: int value
 */

int append_int(char *buf, size_t size, int value)
{
	char numbuf[20];
	size_t idx = 0;
	int start;
	int end;

	if (value == 0)
	{
		return (append(buf, size, "0"));
	}

	if (value < 0)
	{
		value = -value;
		*buf++ = '-';
		size--;
	}

	while (value && idx < sizeof(numbuf) - 1)
	{
		numbuf[idx++] = '0' + (value % 10);
		value /= 10;
	}

	numbuf[idx] = '\0';
	for (start = 0, end = idx - 1; start < end; start++, end--)
	{
		char temp = numbuf[start];

		numbuf[start] = numbuf[end];
		numbuf[end] = temp;
	}

	return (append(buf, size, numbuf));
}
