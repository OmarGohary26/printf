#include "main.h"

/**
 * convert - converter function
 * @num: num
 * @base: base
 * @flags: arg flags
 * @params: parameters
 * Return: string
*/

char *convert(long int num, int base, int flags, params_t *params)
{
	unsigned long n = num;
	static char *arr;
	static char buff[50];
	char *p;
	char s;
	(void)params;

	if (!(flags & CONV_UNSIGNED) && num < 0)
	{
		n = -num;
		s = '-';
	}

	arr = flags & CONV_LOW ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buff[49];
	*p = '\0';

	do
	{
		*--p = arr[n % base];
		n /= base;
	} while (n != 0);

	if (s)
		*--p = s;
	return (p);
}

/**
 * print_unsigned - prints unsigned int
 * @va: arg pointer
 * @params: parameter struct
 * Return: int
*/

int print_unsigned(va_list va, params_t *params)
{
	unsigned long d;

	if (params->l_modifier)
		d = (unsigned long)va_arg(va, unsigned long);
	else if (params->h_modifier)
		d = (unsigned short int)va_arg(va, unsigned int);
	else
		d = (unsigned int)va_arg(va, unsigned int);
	params->unsign = 1;
	return (print_number(convert(d, 10, CONV_UNSIGNED, params), params));
}

/**
 * print_address - prints address
 * @va: arg pointer
 * @params: the parameters struct
 * Return: int
*/

int print_address(va_list va, params_t *params)
{
	unsigned long int n = va_arg(va, unsigned long int);
	char *s;

	if (!n)
		return (_puts("(nil)"));

	s = convert(n, 16, CONV_UNSIGNED | CONV_LOW, params);
	*--s = 'x';
	*--s = '0';
	return (print_number(s, params));
}
