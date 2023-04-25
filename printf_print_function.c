#include "main.h"

/**
 * my_print_char - prints a unique character
 *
 * @my_ap: argument pointer
 * @my_params: the parameters struct
 *
 * Return: number of characters printed
 */

int my_print_char(va_list my_ap, params_t *my_params)
{
	char my_pad_char = ' ';
	unsigned int my_pad = 1, my_sum = 0, my_ch = va_arg(my_ap, int);

	if (my_params->minus_flag)
		my_sum += _putchar(my_ch);
	while (my_pad++ < my_params->width)
		my_sum += _putchar(my_pad_char);
	if (!my_params->minus_flag)
		my_sum += _putchar(my_ch);

	return (my_sum);
}

/**
 * my_print_int - prints a unique integer
 * @my_ap: argument pointer
 * @my_params: the parameters struct
 *
 * Return: number of characters printed
 */
int my_print_int(va_list my_ap, params_t *my_params)
{
	long my_l;

	if (my_params->l_modifier)
		my_l = va_arg(my_ap, long);
	else if (my_params->h_modifier)
		my_l = (short int)va_arg(my_ap, int);
	else
		my_l = (int)va_arg(my_ap, int);
	return (print_normal_number(convert_number(my_l, 10, 0,
			my_params), my_params));
}

/**
 * print_custom_string - prints a string with custom formatting
 * @arg_ptr: pointer to the argument list
 * @params: pointer to the parameters struct
 *
 * Return: the number of characters printed
 */
int print_custom_string(va_list arg_ptr, params_t *params)
{
	char *str = va_arg(arg_ptr, char *);
	char padding_char = ' ';
	unsigned int padding = 0, sum = 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
	{
		case 1:
			str = NULL_STRING;
			break;
	}
	j = padding = _strlen(str);
	if (params->precision < padding)
		j = padding = params->precision;
	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
		{
			for (i = 0; i < padding; i++)
				sum += _putchar(*str++);
		} else
			sum += _puts(str);
	}
	while (j++ < params->width)
	{
		sum += _putchar(padding_char);
	}
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
		{
			for (i = 0; i < padding; i++)
			{
				sum += _putchar(*str++);
			}
		} else
			sum += _puts(str);
	}
	return (sum);
}


/**
 * print_percent_new - prints a percentage sign
 *
 * @arg_ptr: argument pointer
 * @params_struct: the parameters struct
 *
 * Return: the number of characters printed
 */
int print_percent_new(va_list arg_ptr, params_t *params_struct)
{
	(void)arg_ptr;
	(void)params_struct;

	return (_putchar('%'));
}

/**
 * print_custom_S - custom format specifier
 *
 * @arg_ptr: argument pointer
 * @params_struct: the parameters struct
 *
 * Return: the number of characters printed
 */
int print_custom_S(va_list arg_ptr, params_t *params_struct)
{
	char *str_val = va_arg(arg_ptr, char *);
	char *hex_val;
	int char_count = 0;

	if ((int)(!str_val))
		return (_puts(NULL_STRING));

	for (; *str_val; str_val++)
	{
		if ((*str_val > 0 && *str_val < 32) || *str_val >= 127)
		{
			char_count += _putchar('\\');
			char_count += _putchar('x');
			hex_val = convert_number(*str_val, 16, 0, params_struct);
			if (!hex_val[1])
				char_count += _putchar('0');
			char_count += _puts(hex_val);
		}
		else
		{
			char_count += _putchar(*str_val);
		}
	}
	return (char_count);
}
