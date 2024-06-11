#include "main.h"

/**
 * _strncat - two strings together
 * @dest: destination of the string
 * @src: source of the string
 * @n: max number of string
 *
 * concatination
 * Return: destination
 */

char *_strncat(char *dest, char *src, int n)
{
	int e = 0, d = 0;

	while (dest[e] != '\0')
		e++;
	while (src[d] != '\0' && n > d)
	{
		dest[e] = src[d];
		d++;
		e++;
	}
	if (n > 0)
	{
		dest[e] = '\0';
	}

	return (dest);
}
