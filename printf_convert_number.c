#include "main.h"

/**
 * print_hex_upper - prints unsigned hex numbers in uppercase
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: number of bytes printed
 */
int print_hex_upper(va_list ap, params_t *params)
{
	unsigned long val;
	int count = 0;
	char *str;

	if (params->l_modifier)
		val = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		val = (unsigned short int)va_arg(ap, unsigned int);
	else
		val = (unsigned int)va_arg(ap, unsigned int);

	str = convert_number(val, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && val)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	count = print_normal_number(str, params);
	return (count);
}

/**
 * print_hex_lower - Prints an unsigned hex number in lowercase.
 *
 * @ap: A va_list containing the arguments to the function.
 * @params: A pointer toa params_t struct containing any additional param.
 *
 * Return: The number of bytes printed.
 */
int print_hex_lower(va_list ap, params_t *params)
{
	unsigned long num;
	int count = 0;
	char *str;

	if (params->l_modifier)
		num = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		num = (unsigned short int)va_arg(ap, unsigned int);
	else
		num = (unsigned int)va_arg(ap, unsigned int);

	str = convert_number(num, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && num)
	{
		*--str = 'x';
		*--str = '0';
	}

	params->unsign = 1;
	count += print_normal_number(str, params);

	return (count);
}
/**
 * print_custom_octal - prints unsigned octal numbers
 * @arg_list: the argument pointer
 * @params_struct: the parameters struct
 *
 * Return: bytes printed
 */
int print_custom_octal(va_list arg_list, params_t *params_struct)
{
	unsigned long num;
	char *str;
	int byte_count = 0;

	if (params_struct->l_modifier)
		num = (unsigned long)va_arg(arg_list, unsigned long);
	else if (params_struct->h_modifier)
		num = (unsigned short int)va_arg(arg_list, unsigned int);
	else
		num = (unsigned int)va_arg(arg_list, unsigned int);

	str = convert_number(num, 8, CONVERT_UNSIGNED, params_struct);

	if (params_struct->hashtag_flag && num)
		*--str = '0';
	params_struct->unsign = 1;

	return (byte_count += print_normal_number(str, params_struct));
}

/**
 * printUnsignedBinary - prints unsigned binary number
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: number of bytes printed
 */
int printUnsignedBinary(va_list ap, params_t *params)
{
	unsigned int num = va_arg(ap, unsigned int);
	char *binaryStr = convert_number(num, 2, CONVERT_UNSIGNED, params);
	int byteCount = 0;

	if (params->hashtag_flag && num)
		*--binaryStr = '0';

	params->unsign = 1;

	byteCount += print_normal_number(binaryStr, params);

	return (byteCount);
}

