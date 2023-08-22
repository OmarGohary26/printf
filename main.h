#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

#define OUT_BUF_S 1024
#define BF_FLUSH -1

#define NULL_S "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONV_LOW 1
#define CONV_UNSIGNED 2
/**
 * struct parameter - struct to determine parameters
 * @unsign: flag for unsigned
 * @plusflag: flag for "+"
 * @negativeflag: flag for "-"
 * @spaceflag: flag for " "
 * @hashtagflag: flag for "#"
 * @zeroflag: flag for "0"
 * @width: to specify width
 * @precision: to specify precision
 * @h_modifier: on if h_modifier is specified
 * @l_modifier : on if l_modifier is specified
*/

typedef struct parameter
{
	unsigned int unsign	: 1;
	unsigned int plusflag	: 1;
	unsigned int negativeflag	: 1;
	unsigned int spaceflag	: 1;
	unsigned int hashtagflag	: 1;
	unsigned int zeroflag	: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier	: 1;
	unsigned int l_modifier : 1;
} params_t;

/**
 * struct specifier - Struct to take token
 *
 * @specifier: the format of the token
 * @f: the function  to deal with
*/

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* _put.c module*/
int _putchar(int c);
int _puts(char *str);

/* print_funcs.c module*/
int print_char(va_list va, params_t *params);
int print_int(va_list va, params_t *params);
int print_string(va_list va, params_t *params);
int print_perc(va_list va, params_t *params);
int print_string_upper(va_list va, params_t *params);

/* num.c module*/
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list va, params_t *params);
int print_address(va_list va, params_t *params);

/* specify.c module */
int (*get_specifier(char *s)) (va_list va, params_t *params);
int get_print_func(char *s, va_list va, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list va);

/*converter.c module*/
int lower_hex(va_list va, params_t *params);
int upper_HEX(va_list va, params_t *params);
int conv_binary(va_list va, params_t *params);
int conv_octal(va_list va, params_t *params);

/*print_funcs_2.c */
int print_start_stop(char *start, char *stop, char *except);
int reverse_print(va_list va, params_t *params);
int print_rot13(va_list va, params_t *params);

/* print_number.c */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

/* params.c */
void init_params(params_t *params, va_list va);

/* precision.c */
char *get_precision(char *p, params_t *params, va_list va);

/* _printf.c */
int _printf(const char *format, ...);

#endif
