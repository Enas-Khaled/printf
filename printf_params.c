#include "main.h"

/**
 * parameters_init - it delete struct fields and reset buf
 * @params: struct's parameters
 * @ap: pointer_arg
 *
 * Return: void
 */
void parameters_init(params_t *params, va_list ap)
{
	params->unsign = 0;

	params->plus_flag = 0;
	params->space_flag = 0;
	params->hashtag_flag = 0;
	params->zero_flag = 0;
	params->minus_flag = 0;

	params->width = 0;
	params->precision = UINT_MAX;

	params->h_modifier = 0;
	params->l_modifier = 0;
	(void)ap;
}
