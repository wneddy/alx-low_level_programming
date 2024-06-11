#include "main.h"

/**
 * _strcmp - comparing strings
 * @s1: the first string
 * @s2: the second string
 *
 * comparison
 * Return: return comparison
 */

int _strcmp(char *s1, char *s2)
{
	int d = 0, comprn = 0;

	while (s1[d] != '\0' && s2[d] != '\0' && comprn == 0)
	{
		comprn = s1[d] - s2[d];
		d++;
	}

	return (comprn);
}
