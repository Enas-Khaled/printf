#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#define BUFF_OUT_SIZE 1024
#define THE_BUFFER -1
#define NULL_STRING "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED  2

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus_flag: on if plus_flag specified
 * @space_flag: case in  hashtag_flag specified
 * @hashtag_flag: on if _flag specified
 * @zero_flag: in case_flag specified
 * @minus_flag: in case _flag specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @h_modifier: in case  h_modifier is specified
 * @l_modifier: in case l_modifier is specified
 *
 */
typedef struct parameters
{
	unsigned int unsign         : 1;
	unsigned int plus_flag      : 1;
	unsigned int space_flag     : 1;
	unsigned int hashtag_flag   : 1;
	unsigned int zero_flag      : 1;
	unsigned int minus_flag     : 1;
	unsigned int width;
	unsigned int  precision;
	unsigned int h_modifier     : 1;
	unsigned int l_modifier    : 1;
} params_t;

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated of value
*/

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, paramters *);
} specifier_t;

/* printf_put.c module */
int _puts(char *str);
int _putchar(int c);

/*  print_function.c module */
int my_print_char(va_list my_ap, my_params_t *my_params);
int my_print_int(va_list my_ap, my_params_t *my_params);
int print_custom_string(va_list arg_ptr, params_t *params);
int print_percent_new(va_list arg_ptr, params_t *params_struct);
int print_custom_S(va_list arg_ptr, params_t *params_struct);

/* printf_number.c module */
char *convert_number(long int num, int base, int conversion_flags
	, params_t *params);
int print_my_unsigned(va_list ap, params_t *params);
int my_print_address(va_list my_ap, my_params_t *my_params);

/* printf_specifer.c module */
int (*my_get_specifier(char *s)) (va_list ap, params_t *params);
int toget_my_print_func(char *s, va_list ap, params_t *params);
int toget_my_flag(char *s, params_t *params);
int toget_my_modifier(char *s, params_t *params);
char *toget_my_width(char *s, params_t *params, va_list ap);

/* printf_convert_number.c module */
int print_hex_lower(va_list ap, params_t *params);
int print_hex_upper(va_list ap, params_t *params);
int printUnsignedBinary(va_list ap, params_t *params);
int print_custom_octal(va_list arg_list, params_t *params_struct);

/* printf_simple_printers.c modules */
int print_string_from_to(char *str_start, char *str_stop, char *str_except);
int print_reverse(va_list ap, params_t *params);
int print_rot13_string(va_list ap, params_t *params_1);

/* printf_print_number.c module */
int _atoi(char *s);
int _isdigit(int c);
int _strlen(char *s);
int print_normal_number(char *str, params_t *params);
int print_number_right_to_shift(char *str, params_t *params);
int print_number_left_to_shift(char *str, params_t *params);
/* printf_params.c module */
void parameters_init(params_t *params, va_list ap);
/* printf_string_fields.c module */
char *my_get_precision(char *p, params_t *params, va_list ap);

/* _printf.c module */
int _printf(const char *format, ...);

#endif
