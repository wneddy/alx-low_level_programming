#include "main.h"

/**
 * _puts - printing out strings to stdout
 * @str: string set
 *
 * Return: null return value.
 */

void _puts(char *str)
{
	int v = 0;

	while (str[v] != '\0')
	{
		_putchar(str[v]);
		v++;
	}
	_putchar('\n');
}
