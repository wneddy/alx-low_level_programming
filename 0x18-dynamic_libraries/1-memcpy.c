#include "main.h"

/**
 * _memcpy - copying a memory from
 * one source to another
 * @dest: where to copy
 * @src: copy from where
 * @n: size to be copied
 *
 * Return: copied string
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int l;

	l = 0;

	while (l < n)
	{
		dest[l] = src[l];
		l++;
	}

	return (dest);
}
