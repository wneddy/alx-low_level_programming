#include "main.h"

/**
 * _strchr - locating a certain character
 * @s: set string
 * @c: iterator
 *
 * Return: current position
 * else null
 */

char *_strchr(char *s, char c)
{
	int e = 0;

	while (s[e] != '\0')
	{
		if (s[e] == c)
		{
			return (s + e);
		}
		e++;
	}
	if (c == '\0')
		return (s + e);
	return (NULL);
}
