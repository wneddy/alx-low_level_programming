#include "main.h"

/**
 * _isdigit - checking out for digit
 *
 * @c : check it status
 *
 * Return: 1 if c is digit else 0
 */

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
