#include "main.h"

/**
 * flip_bits - function to return the number of bits
 * one would like flip to get from one no. to another.
 * @n: no.
 * @m: no. to flip n to.
 *
 * Return: bits flipped.
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int operator = n ^ m, bts = 0;

	while (operator > 0)
	{
		bts += (operator & 1);
		operator >>= 1;
	}

	return (bts);
}
