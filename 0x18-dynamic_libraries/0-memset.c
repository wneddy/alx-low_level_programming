#include "main.h"

/**
 * _memset - filling a memory with a constant byte
 * @s: set string
 * @b: character rep
 * @n: n size of the memory
 *
 * Return: set(0)
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int x;

	x = 0;
	while (x < n)
	{
		s[x] = b;
		x++;
	}

	return (s);
}
