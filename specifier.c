#include "main.h"

/**
<<<<<<< HEAD
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
=======
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
>>>>>>> 9cbac79437d17d72f034ff6d6b9bd8a8ca2d5628
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
<<<<<<< HEAD
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
=======

	int i = 0;

	while (specis[i].specifier)
	{
		if (*s == specis[i].specifier[0])
		{
			return (specis[i].f);
>>>>>>> 9cbac79437d17d72f034ff6d6b9bd8a8ca2d5628
		}
		i++;
	}
	return (NULL);
}

/**
<<<<<<< HEAD
 * get_print_func - gets the format functions
 * @s: the string format
 * @va: the arg pointer
 * @params: the struct
 * Return: number of bytes
*/

=======
 * get_print_func - find the format of the function
 * @s: format string
 * @va: the pointer
 * @params: parameters struct
 * Return: number of bytes printed
*/
>>>>>>> 9cbac79437d17d72f034ff6d6b9bd8a8ca2d5628
int get_print_func(char *s, va_list va, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(va, params));
	return (0);
}

/**
<<<<<<< HEAD
 * get_flag - find flag function
 * @s: string
 * @params: the parameters struct
 * Return: flag
*/

=======
 * get_flag - find the flag
 * @s: format
 * @params: params struct
 * Return: if flag is valid
*/
>>>>>>> 9cbac79437d17d72f034ff6d6b9bd8a8ca2d5628
int get_flag(char *s, params_t *params)
{
	int i = 0;

<<<<<<< HEAD
	switch (*s)
	{
		case '+':
			i = params->plusflag = 1;
			break;
		case ' ':
			i = params->spaceflag = 1;
			break;
		case '#':
			i = params->hashtagflag = 1;
			break;
		case '-':
			i = params->negativeflag = 1;
			break;
		case '0':
			i = params->zeroflag = 1;
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
=======
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

>>>>>>> 9cbac79437d17d72f034ff6d6b9bd8a8ca2d5628
	return (i);
}

/**
<<<<<<< HEAD
 * get_width - gets width from string
 * @s: string
 * @params: struct
 * @va: arg pointer
 * Return: pointer
=======
 * get_width - gets the width
 * @s: format string
 * @params: parameters struct
 * @va: argument pointer
 * Return: new pointer
>>>>>>> 9cbac79437d17d72f034ff6d6b9bd8a8ca2d5628
*/

char *get_width(char *s, params_t *params, va_list va)
{
<<<<<<< HEAD
	int digit = 0;

	if (*s == '*')
	{
		digit = va_arg(va, int);
		s++
=======
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(va, int);
		s++;
>>>>>>> 9cbac79437d17d72f034ff6d6b9bd8a8ca2d5628
	}
	else
	{
		while (_isdigit(*s))
<<<<<<< HEAD
			digit = digit * 10 + (*s++ - '0');
	}
	params->width = digit;
=======
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
>>>>>>> 9cbac79437d17d72f034ff6d6b9bd8a8ca2d5628
	return (s);
}
