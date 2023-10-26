#include "main.h"

/**
 * clear_bit - function to set the
 * value of a bit to 0 at a given index.
 * @n: * to the bit.
 * @index: position, index starting from 0 of the bit to set.
 *
 * Return: success
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	*n &= ~(1 << index);

	return (1);
}
