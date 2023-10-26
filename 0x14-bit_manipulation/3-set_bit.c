#include "main.h"

/**
 * set_bit - function to set value of bit
 * to 1 at given index.
 * @n: * to the bit.
 * @index: position to the set index.
 *
 * Return: success
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	*n ^= (1 << index);

	return (1);
}
