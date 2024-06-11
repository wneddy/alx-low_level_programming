#include "lists.h"
#include <stdio.h>

/**
 * print_dlistint - function to print elements in list
 * @h: pointer to the list
 *
 * Return: no. of nodes/members
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t members = 0;

	if (!h)
	{
		return (0);
	}

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		members++;
	}

	return (members);
}
