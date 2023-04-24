#include "main.h"
/**
 * print_string_from_to - Prints a string from a start character to a stop
 *                        character, excluding a specified exception character.
 * @str_start: A pointer to the start character of the string to print.
 * @str_stop: A pointer to the stop character of the string to print.
 * @str_except: A pointer to the exception character to exclude from printing.
 *
 * Return: The number of characters printed, excluding the exception character.
 */
int print_string_from_to(char *str_start, char *str_stop, char *str_except)
{
	int sum = 0;

	while (str_start <= str_stop)
	{
		if (str_start != str_except)
		{
			sum += putchar(*str_start);
		}
	str_start++;
	}

	return (sum);
}
/**
 * print_reverse - Prints a string in reverse order.
 *
 * @ap: A va_list containing the arguments to the function.
 * @params_1: A pointer to a params_t struct containing .
 *
 * Return: The number of characters printed.
 */
int print_reverse(va_list ap, params_t *params_1)
{
	int len, sum = 0;
	char *str = va_arg(ap, char *);
	(void)params_1;

	if (str)
	{
		for (len = 0; *str; str++)
		{
			len++;
		}
		str--;
		for (; len > 0; len--, str--)
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}

/**
 * print_rot13_string - Prints a string using the ROT13 encryption method.
 *
 * @ap: A va_list containing the arguments to the function.
 * @params_1: A pointer to a params_t struct containing any additional param.
 *
 * Return: The number of characters printed.
 */
int print_rot13_string(va_list ap, params_t *params_1)
{
	int i, index;
	int counter = 0;
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *str = va_arg(ap, char *);
	(void)params_1;

	i = 0;
	index = 0;
	while (str[i])
	{
		if (((str[i] >= 'A') && (str[i] <= 'Z'))
|| ((str[i] >= 'a') && (str[i] <= 'z')))
		{
			index = str[i] - 65;
			counter += _putchar(rot13[index]);
		}
		else
		{
			counter += _putchar(str[i]);
		}
		i++;
	}
	return (counter);
}
