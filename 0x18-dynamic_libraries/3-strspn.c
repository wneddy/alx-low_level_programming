#include "main.h"

/**
 * _strspn - checking the initial
 * segment of a string
 * @s: set string
 * @accept: checkers
 *
 * Return: no. of bytes found
 */

unsigned int _strspn(char *s, char *accept)
{
	int x = 0, y;
	unsigned int check = 0;


	while (s[x] != '\0')
	{
		y = 0;
		while (accept[y] != '\0')
		{
			if (s[x] == accept[y])
			{
				check++;
				break;
			}
			y++;
		}
		if (s[x] != accept[y])
			break;
		x++;
	}
	return (check);
}
