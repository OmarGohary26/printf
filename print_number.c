#include "main.h"

/**
 * _isdigit - para is digit or not
 * @c: para
 * Return: int
*/

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - gets the length of the string
 * @s: para
 * Return: int
*/

int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - print number
 * @str: para
 * @params: para
 * Return: int
*/

int print_number(char *str, params_t *params)
{
	unsigned int i = _strlen(str);
	int neg = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!params->negativeflag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}
