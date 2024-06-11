#include "main.h"

/**
 * _strstr - locating a substring
 * find the first occurence of substring
 * @haystack: set string for saerch
 * @needle: substring
 *
 * Return: located string else null
 */

char *_strstr(char *haystack, char *needle)
{
	int e, d;

	for (e = 0; haystack[e] != '\0'; e++)
	{
		for (d = 0; needle[d] != '\0';)
		{
			if (needle[d] == haystack[e + d])
				d++;
			else
				break;
		}
		if (needle[d] == '\0')
			return (haystack + e);
	}
	return (NULL);
}
