#include "main.h"

/**
 * print_char - a function that prints characters
 * @va: arg pointer
 * @params: struct
 * Return: number of characters printed
*/

int print_char(va_list va, params_t *params)
{
	char pc = ' ';
	unsigned int p = 1, total = 0, c = va_arg(va, int);

	if (params->negativeflag)
		total += _putchar(c);
	while (p++ < params->width)
		total += _putchar(pc);
	if (!params->negativeflag)
		total += _putchar(c);
	return (total);
}

/**
 * print_int - a function that prints integers
 * @va: arg pointer
 * @params: struct
 * Return: number printed
*/

int print_int(va_list va, params_t *params)
{
	long ln;

	if (params->l_modifier)
		ln = va_arg(va, long);
	else if (params->h_modifier)
		ln = (short int)va_arg(va, int);
	else
		ln = (int)va_arg(va, int);
	return (print_number(convert(ln, 10, 0, params), params));
}

/**
 * print_string - a function that prints string
 * @va: arg pointer
 * @params: struct
 * Return: number of strings
*/

int print_string(va_list va, params_t *params)
{
	char *st = va_arg(va, char *), pc = ' ';
	unsigned int p = 0, total = 0, i = 0, j;

	(void)params;
	switch ((int)(!st))
		case 1:
			st = NULL_S;
	j = p = _strlen(st);
	if (params->precision < p)
		j = p = params->precision;

	if (params->negativeflag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < p; i++)
				total += _putchar(*st++);
		else
			total += _puts(st);
	}
	while (j++ < params->width)
		total += _putchar(pc);
	if (!params->negativeflag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < p; i++)
				total += _putchar(*st++);
		else
			total += _puts(st);
	}
	return (total);
}

/**
 * print_perc - print percent sign
 * @va: arg pointer
 * @params: the parameters struct
 * Return: int
*/

int print_perc(va_list va, params_t *params)
{
	(void)va;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_string_upper - print upper case strings
 * @va: arg pointer
 * @params: struct ara
 * Return: int
*/

int print_string_upper(va_list va, params_t *params)
{
	int sum = 0;
	char *s = va_arg(va, char *);
	char *hx;

	if ((int) (!s))
		return (_puts(NULL_S));
	for (; *s; s++)
	{
		if ((*s > 0 && *s < 32) || *s >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hx = convert(*s, 16, 0, params);
			if (!hx[1])
				sum += _putchar('0');
			sum += _puts(hx);
		}
		else
		{
			sum += _putchar(*s);
		}
	}
	return (sum);
}
