#include "main.h"

/**
 * get_specifier - finds the format
 * @s: format string
 *
 * Return: void
*/

int (*get_specifier(char *s)) (va_list va, params_t *params)
{
	specifier_t specis[] = {
		{"c", print_char},
		{"d", print_int},
		{"s", print_string},
		{"i", print_int},
		{"%", print_percent},
		{"u", print_unsigned},
		{"b", print_binary},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};

	int i = 0;

	while (specis[i].specifier)
	{
		if (*s == specis[i].specifier[0])
		{
			return (specis[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print_func - find the format of the function
 * @s: format string
 * @va: the pointer
 * @params: parameters struct
 * Return: number of bytes printed
*/
int get_print_func(char *s, va_list va, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(va, params));
	return (0);
}

/**
 * get_flag - find the flag
 * @s: format
 * @params: params struct
 * Return: if flag is valid
*/
int get_flag(char *s, params_t *params)
{
	int i = 0;

	if (*s == '+')
		i = params->plusflag = 1;
	else if (*s == ' ')
		i = params->spaceflag = 1;
	else if (*s == '#')
		i = params->hashtagflag = 1;
	else if (*s == '-')
		i = params->negativeflag = 1;
	else if (*s == '0')
		i = params->zeroflag = 1;

	return (i);
}

/**
 * get_width - gets the width
 * @s: format string
 * @params: parameters struct
 * @va: argument pointer
 * Return: new pointer
*/

char *get_width(char *s, params_t *params, va_list va)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(va, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s);
}
