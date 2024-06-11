#include "main.h"


/**
 * _strpbrk - browser for strings
 * @s: checker
 * @accept: comparison
 *
 * Return: for byte, else null
 */
char *_strpbrk(char *s, char *accept)
{
	int c, v;

	for (c = 0; s[c] != '\0'; c++)
	{
		for (v = 0; accept[v] != '\0'; v++)
		{
			if (s[c] == accept[v])
			{
				return (s + c);
			}
		}
	}
	return (NULL);
}
