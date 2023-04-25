#include "main.h"

/**
 * convert_number - converts number to string representation
 * @num: number to convert
 * @base: base to convert to
 * @conversion_flags: conversion flags
 * @params: parameter struct
 * Return: pointer to string representation of number
*/
char *convert_number(long int num, int base, int conversion_flags,
params_t *params)
{
	static char *char_array;
	static char buffer[50];
	char sign = 0;
	char *str_ptr;
	unsigned long int n = num;
	(void)params;

	if (!(conversion_flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	char_array = conversion_flags & CONVERT_LOWERCASE ?
		"0123456789abcdef" : "0123456789ABCDEF";
	str_ptr = &buffer[49];
	*str_ptr = '\0';

	do {
	*--str_ptr = char_array[n % base];
	n /= base;
	} while (n != 0);

	if (sign)
	*--str_ptr = sign;
	return (str_ptr);
}

/**
 * print_my_unsigned - prints unique unsigned integer numbers
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number of bytes printed
 */
int print_my_unsigned(va_list ap, params_t *params)
{
	unsigned long my_ulong;

	if (params->l_modifier)
		my_ulong = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		my_ulong = (unsigned short int)va_arg(ap, unsigned int);
	else
		my_ulong = (unsigned int)va_arg(ap, unsigned int);

	params->unsign = 1;

	return (print_normal_number(convert_number(my_ulong, 10, CONVERT_UNSIGNED,
params), params));
}

/**
 * my_print_address - prints a unique address
 * @my_ap: argument pointer
 * @my_params: the parameters struct
 *
 * Return: number of bytes printed
 */
int my_print_address(va_list my_ap, params_t *my_params)
{
	unsigned long int my_ulong = va_arg(my_ap, unsigned long int);
	char *my_str;

	if (!my_ulong)
	return (_puts("(nil)"));
	my_str = convert_number(my_ulong, 16, CONVERT_UNSIGNED |
CONVERT_LOWERCASE, my_params);
	*--my_str = 'x';
	*--my_str = '0';

	return (print_normal_number(my_str, my_params));
}

