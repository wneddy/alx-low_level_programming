#include "main.h"

/**
 * _strcpy - string copied to another
 * by src
 * @dest: location to copy
 * @src: copy from
 *
 * Return: desired destination
 */
char *_strcpy(char *dest, char *src)
{
	int cnt = 0, size;

	while (src[cnt] != '\0')
	{
		cnt++;
	}
	size = cnt;

	for (cnt = 0; cnt <= size; cnt++)
	{
		dest[cnt] = src[cnt];
	}
	return (dest);
}
