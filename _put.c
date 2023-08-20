#include "main.h"

/**
 * _puts - prints a string
 * @str: para
 *
 * Return: void
*/

int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 * _putchar - prints the character
 * @c: the character to print
 * Return: On success 1 , on Error -1
*/

int _putchar(int c);
{
	static int i;
	static char buf[OUT_BUF_S];

	if (c == BF_FLUSH || i >= OUT_BUF_S)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BF_FLUSH)
		buf[i++] = c;
	return (1);
}
