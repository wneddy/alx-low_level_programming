#include "lists.h"

/**
 * get_dnodeint_at_index - function to print index of
 * number.
 * @head: pointer to the list.
 * @index: position of the node searched.
 *
 * Return: position of the node in the list.
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current_n = head;
	unsigned int counter = 0;

	while (current_n != NULL && counter < index)
	{
		current_n = current_n->next;
		counter++;
	}

	if (counter != index)
	{
		return (NULL);
	}

	return (current_n);
}
