#include "main.h"

/**
 * get_bit - function to return value of
 * a bit at a given index
 * @n: bit to return.
 * @index: index at which we are getting the value
 *
 * Return: success
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	if ((n & (1 << index)) == 0)
		return (0);

	return (1);
}
