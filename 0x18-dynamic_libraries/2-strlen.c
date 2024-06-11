#include "main.h"

/**
 * _strlen - counting string length
 * @s : the set string
 *
 * Return: 0 (done)
 */

int _strlen(char *s)
{
	int size_of_string = 0;

	while (*s != '\0')
	{
		size_of_string++;
		s++;
	}

	return (size_of_string);
}
