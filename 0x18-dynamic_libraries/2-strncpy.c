#include "main.h"

/**
 * _strncpy - copying strings from
 * source to destistion
 * @dest: destination of the string
 * @src: source of the string to copy
 * @n: max number of array
 *
 * string copy function
 * Return: result
 */

char *_strncpy(char *dest, char *src, int n)
{
	int e = 0, d = 0;

	while (n > d)
	{
		if (src[d] == '\0')
		{
			for (; d < n; d++)
			{
				dest[e] = '\0';
				e++;
			}
		}
		else
		{
			dest[e] = src[d];
			d++;
			e++;
		}
	}

	return (dest);
}
