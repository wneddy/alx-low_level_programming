#include "main.h"

/**
 * get_endianness - function to checks the endianness.
 *
 * Return: 0 big endian, 1 - little endian.
 */

int get_endianness(void)
{
	int val = 1;
	char *endn = (char *)&val;

	if (*endn == 1)
	{
		return (1);
	}

	return (0);
}
