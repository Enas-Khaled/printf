#include "main.h"

/**
 * _printf - works as printf prints anything
 * @format: format to print
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list ap;
	char *p, *start;
	params_t params = PARAMS_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		parameters_init(&params, ap);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (toget_my_flag(p, &params)) /* while char at p is flag char */
		{
			p++; /* next char */
		}
		p = toget_my_width(p, &params, ap);
		p = my_get_precision(p, &params, ap);
		if (toget_my_modifier(p, &params))
			p++;
		if (!my_get_specifier(p))
			sum += print_string_from_to(start, p,
				params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			sum += toget_my_print_func(p, ap, &params);
	}
	_putchar(THE_BUFFER);
	va_end(ap);
	return (sum);
}

