#include "main.h"

/**
 * _printf - a function that prints output
 * @format: the formatted string
 * Return: num of bytes printed
*/

int _printf(const char *format, ...)
{
	int total = 0;
	va_list va;
	char *ptr, *strt;
	params_t para = PARAMS_INIT;

	va_start(va, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (ptr = (char *)format; *ptr; ptr++)
	{
		init_params(&para, va);
		if (*ptr != '%')
		{
			total += _putchar(*ptr);
			continue;
		}
		strt = ptr;
		ptr++;
			while (get_flag(ptr, &para))
			{
				ptr++;
			}
		ptr = get_width(ptr, &para, va);
		ptr = get_precision(ptr, &para, va);
		if (get_modifier(ptr, &para))
			ptr++;
		if (!get_specifier(ptr))
			total += print_start_stop(strt, ptr,
			para.l_modifier || para.h_modifier ? ptr - 1 : 0);
		else
			total += get_print_func(ptr, va, &para);
	}
	_putchar(BF_FLUSH);
	va_end(va);
	return (total);
}
