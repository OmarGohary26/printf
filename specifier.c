#include "main.h"

/**
 * gtet_specifier - specifies the fuction format
 * @s: the format string
 * Return: number of bytes
*/

int (*get_specifier(char *s)(va_list va, params_t *params))
{
	specifier_t specifier[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"s", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print_func - gets the format functions
 * @s: the string format
 * @va: the arg pointer
 * @params: the struct
 * Return: number of bytes
*/

int get_print_func(char *s, va_list va, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(va, params));
	return (0);
}

/**
 * get_flag - find flag function
 * @s: string
 * @params: the parameters struct
 * Return: flag
*/

int get_flag(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->hashtagt_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - gets the modifier function
 * @s: string
 * @params: struct of parameters
 * Return: validity
*/

int get_modifier(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = params->h_modifier = 1;
			break;
		case 'l':
			i = params->l_modifier = 1;
			break;
	}
	return (i);
}

/**
 * get_width - gets width from string
 * @s: string
 * @params: struct
 * @va: arg pointer
 * Return: pointer
*/

char *get_width(char *s, params_t *params, va_list va)
{
	int digit = 0;

	if (*s == '*')
	{
		digit = va_arg(va, int);
		s++
	}
	else
	{
		while (_isdigit(*s))
			digit = digit * 10 + (*s++ - '0');
	}
	params->width = digit;
	return (s);
}
