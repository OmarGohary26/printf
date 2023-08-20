#include "main.h"

/**
 * get_precision - a function that extract precision from the format string
 * @p: format string
 * @params: the parameters struct
 * @va: the argument pointer
 * Return: a pointer
*/

char *get_precision(char *p, params_t *params, va_list va)
{
	int digit = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		digit = va_arg(va, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			digit = digit * 10 + (*p++ - '0');
	}
	params->precision = digit;
	return (p);
}
