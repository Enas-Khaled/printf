/**
 * _printf - printf function
 * @format: argumnt to count next arguments
 * return: total numbers of chars to print
 */
int _printf(const char *format, ...)
{
	int total = 0;
	char c, *str;
	va_list arguments;

	va_start(arguments, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c = (char) va_arg(arguments, int);
				write(1, &c, 1);
				total++;
			}
			else if (*format == 's')
			{
				str = va_arg(arguments, char *);
				if (str == NULL)
				{
					return (-1);
				}
				while (*str != '\0')
				{
					write(1, str, 1);
					str++;
					total++;
				}
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				total++;
			}
		}
		else
		{
			write(1, format, 1);
			total++;
		}
		format++;
	}
	va_end(arguments);
	return (total);
}
