#include "main.h"
<<<<<<< HEAD
/**
 * _printf - a function that prints
 * @format: specify how the output should be formatted
 * Return: number of digits
 */
int _printf(const char *format, ...)
{
	va_list list;
	int cont = 0, i = -1;
	int (*z)(va_list);

	va_start(list, format);

	if (format != NULL)
	{
		i = 0;
		for (; format[cont] != '\0'; i++, cont++)
		{
			if (format[cont] != '%')
				_putchar(format[cont]);
			else if (format[cont] == '%' && format[cont + 1] == '\0')
			{
				return (-1);
			}
			else if (format[cont] == '%' && format[cont + 1] != '\0')
			{
				z = get_function(format[cont + 1]);
				if (z == NULL)
					_putchar(format[cont]);
				else
				{
					i = (i + z(list)) - 1;
					cont++;
				}
			}
		}
	}
	va_end(list);
	return (i);
=======

/**
 * _printf - prints anything
 * @format: the format string
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
		init_params(&params, ap);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params)) /*while char st p is flag char */
		{
			p++; /* next char */
		}
		p = get_width(p, &params, ap);
		p = get_precision(p, &params, ap);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			sum += print_from_to(start, p,
					params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			sum += get_print_func(p, ap, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (sum);
>>>>>>> mywork
}
