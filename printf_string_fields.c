#include "main.h"

/**
 * my_get_precision - gets the precision from the format string
 * @p: the format string
 * @params: the parameters struct
 * @ap: the argument pointer
 *
 * Return: new pointer
 */
char *my_get_precision(char *p, params_t *params, va_list ap)
{
	int di = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		di = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			di = di * 10 + (*p++ - '0');
	}
	params->precision = di;
	return (p);
}
