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

/**
 * print_number_right_shift - print a number with option
 * @str: base number as string
 * @params: the parameter struct
 * Return: int
*/
int print_number_right_shift(char *str, params_t *params)
{
	unsigned int n = 0;
	unsigned int n1, n2;
	unsigned int i = _strlen(str);
	char p_char = ' ';

	if (params->zeroflag && !params->negativeflag)
		p_char = '0';
	n1 = n2 = (!params->unsign && *str == '-');
	if (n1 && i < params->width && p_char == '0' && !params->negativeflag)
		str++;
	else
		n1 = 0;
	if ((params->plusflag && !n2) ||
		(!params->plusflag && params->spaceflag && !n2))
		i++;
	if (n1 && p_char == '0')
		n += _putchar('-');
	if (params->plusflag && !n2 && p_char == '0' && !params->unsign)
		n += _putchar('+');
	else if (!params->plusflag && params->spaceflag &&
		!n2 && !params->unsign && params->zeroflag)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar(p_char);

	if (n1 && p_char == ' ')
		n += _putchar('-');

	if (params->plusflag && !n2 && p_char == ' ' && !params->unsign)
		n += _putchar('+');
	else if (!params->plusflag && params->spaceflag && !n2 &&
			!params->unsign && !params->zeroflag)
	{
		n += _putchar(' ');
	}
	n += _puts(str);
	return (n);
}
/**
 * print_number_left_shift - print a number with option
 * @str: base number as string
 * @params: the parameter struct
 * Return: int
*/

int print_number_left_shift(char *str, params_t *params)
{
	unsigned int n = 0;
	unsigned int n1, n2;
	unsigned int i = _strlen(str);
	char p_char = ' ';

	if (params->zeroflag && !params->negativeflag)
		p_char = '0';
	n1 = n2 = (!params->unsign && *str == '-');
	if (n1 && i < params->width && p_char == '0' && !params->negativeflag)
		str++;
	else
		n1 = 0;

	if (params->plusflag && !n2 && !params->unsign)
	{
		n += _putchar('+');
		i++;
	}
	else if (params->spaceflag && !n2 && !params->unsign)
	{
		n += _putchar(' ');
		i++;
	}

	n += _puts(str);
	while (i++ < params->width)
		n += _putchar(p_char);

	return (n);
}
