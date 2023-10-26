#include "main.h"

/**
 * binary_to_uint - function to convert binary number
 * to unsigned int.
 * @b: no to convert.
 *
 * Return: converted no.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int a;
	int length, base2;

	if (!b)
	{
		return (0);
	}
	a = 0;

	for (length = 0; b[length] != '\0'; length++)
		;

	for (length--, base2 = 1; length >= 0; length--, base2 *= 2)
	{
		if (b[length] != '0' && b[length] != '1')
		{
			return (0);
		}

		if (b[length] & 1)
		{
			a += base2;
		}
	}

	return (a);
}
