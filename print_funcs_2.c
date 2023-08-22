#include "main.h"

/**
 * print_start_stop - printing char adresses
 * @start: starting address
 * @stop: stopping address
 * @except: except address
 * Return: number of bytes
*/

int print_start_stop(char *start, char *stop, char *except)
{
	int total = 0;

	while (start <= stop)
	{
		if (start != except)
			total += _putchar(*start);
		start++;
	}
	return (total);
}

/**
 * reverse_print - prints the string in reverse
 * @va: string
 * @params: struct
 * Return: number of bytes
*/

int reverse_print(va_list va, params_t *params)
{
	int length, total = 0;
	char *st = va_arg(va, char *);
	(void)params;

	if (st)
	{
		for (length = 0; *st; st++)
			length++;
		st--;
		for (; length > 0; length--, st--)
			total += _putchar(*st);
	}
	return (total);
}

/**
 * print_rot13 - prints the string in rot13
 * @va: string
 * @params: struct
 * Return: number bof bytes
*/

int print_rot13(va_list va, params_t *params)
{
	int x, indx;
	int ctr = 0;
	char array[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";
	char *p = va_arg(va, char *);
	(void)params;

	x = 0;
	indx = 0;
	while (p[x])
	{
		if ((p[x] >= 'A' && p[x] <= 'Z')
				|| (p[x] >= 'a' && p[x] <= 'z'))
		{
			indx = p[x] - 65;
			ctr += _putchar(array[indx]);
		}
		else
			ctr += _putchar(p[x]);
		i++;
	}
	return (ctr);
}
