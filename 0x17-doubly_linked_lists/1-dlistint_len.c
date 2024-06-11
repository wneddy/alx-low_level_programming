#include "lists.h"

/**
 * dlistint_len - function to return the numbers of
 * elements in a linked list.
 * @h: pointers to the lits.
 *
 * Return: number of elements.
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t elements = 0;

	while (h != NULL)
	{
		elements++;
		h = h->next;
	}

	return (elements);
}
