#include "main.h"
/**
 * _putchar - prints char to stdout
 * @c: char to print
 *
 * Return: 1 success.-1 error.
 */
int _putchar(int c)
{
	static int i;
	static char buff[BUFF_OUT_SIZE];

	if (c == THE_BUFFER || i >= BUFF_OUT_SIZE)
	{
		write(1, buff, i);
		i = 0;
	}
	if (c != THE_BUFFER)
		buff[i++] = c;
	return (1);
}


/**
 * _puts - writes a string and newline
 * @str: string to print
 *
 * Return: nothing
 */
int _puts(char *str)
{
	char *arr = str;

	while (*str)
		_putchar(*str++);
	return (str - arr);
}
