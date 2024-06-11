#include "main.h"

/**
 * _isalpha - checking alphabets
 * Edward did the coding
 * @c : check state of c letter
 * Return: 1 for lowercase or uppercase else 0
 */

int _isalpha(int c)
{
	return ((c >= 97 && c <= 122) || (c >= 65 && c <= 90));
}
