#include "main.h"

/**
 * print_hex - a function that prints uns hex numbers in lowercase
 * @va: arg pointer
 * @params: struct
 * Return: bytes printed
*/

int print_hex(va_list va, params_t *params)
{
	unsigned long d;
	int ctr = 0;
	char *st;

	if (params->l_modifier)
		d = (unsigned long)va_arg(va, unsigned long);
	else if (params->h_modifier)
		d = (unsigned short int)va_arg(va, unsigned int);
	else
		d = (unsigned int)va_arg(va, unsigned int);

	st = convert(d, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtagflag && d)
	{
		*--st = 'x';
		*--st = '0';
	}
	params->unsign = 1;
	return (ctr += print_number(st, params));
}

/**
 * print_HEX - a function that prints uns hex numbers in uppercase
 * @va: arg pointer
 * @params: struct
 * Return: number of bytes
*/

int print_HEX(va_list va, params_t *params)
{
	unsigned long d;
	int ctr = 0;
	char *st;

	if (params->l_modifier)
		d = (unsigned long)va_arg(va, unsigned long);
	else if (params->h_modifier)
		d = (unsigned short int)va_arg(va, unsigned int);
	else
		d = (unsigned int)va_arg(va, unsigned int);

	st = convert(d, 16, CONVERT_UNSIGNED, params);
	if (params->hashtagflag && d)
	{
		*--st = 'X';
		*--st = '0';
	}
	params->unsign = 1;
	return (ctr += print_number(st, params));
}

/**
 * print_binary - a function that prints unsigned binary number
 * @va: ag pointer
 * @params: struct
 * Return: number of bytes
*/

int print_binary(va_list va, params_t *params)
{
	unsigned int num = va_arg(va, unsigned int);
	char *st = convert(num, 2, CONVERT_UNSIGNED, params);
	int ctr = 0;

	if (params->hhashtagflag && num)
		*--st = '0';
	params->unsign = 1;
	return (ctr += print_number(st, params));
}

/**
 * print_octal - a function that prints uns octal numbers
 * @va: arg pointer
 * @params: struct
 * Return: number of bytes
*/

int print_octal(va_list va, params_t *params)
{
	unsigned long d;
	char *st;
	int ctr = 0;

	if (params->l_modifier)
		d = (unsigned long)va_arg(va, unsigned long);
	else if (params->h_modifier)
		d = (unsigned short int)va_arg(va, unsigned int);
	else
		d = (unsigned int)va_arg(va, unsigned int);
	st = convert(d, 8, CONVERT_UNSIGNED, params);

	if (params->hashtagflag && d)
		*--st = '0';
	params->unsign = 1;
	return (ctr += print_number(st, params));
}
