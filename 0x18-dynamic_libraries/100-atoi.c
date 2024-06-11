#include "main.h"
#include <stdio.h>

/**
 * _atoi - converting strings to numbers
 *
 * @s : prototypes parameter
 * no use of long
 * follow up on the questions
 *
 * Return: (output)
 */

int _atoi(char *s)
{
	unsigned int cnt = 0, sz = 0, e = 0, d = 1, a = 1, w;

	while (*(s + cnt) != '\0')
	{
		if (sz > 0 && (*(s + cnt) < '0' || *(s + cnt) > '9'))
			break;

		if (*(s + cnt) == '-')
			d *= -1;

		if ((*(s + cnt) >= '0') && (*(s + cnt) <= '9'))
		{
			if (sz > 0)
				a *= 10;
			sz++;
		}
		cnt++;
	}

	for (w = cnt - sz; w < cnt; w++)
	{
		e = e + ((*(s + w) - 48) * a);
		a /= 10;
	}
	return (e * d);
}
