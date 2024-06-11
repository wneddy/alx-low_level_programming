#include "lists.h"

/**
 * sum_dlistint - function to loop through the
 * list summing all the variables.
 * @head: pointer to the list.
 *
 * Return: sum of the nodes.
 */

int sum_dlistint(dlistint_t *head)
{
	dlistint_t *list = head;
	int sum = 0;

	while (list != NULL)
	{
		sum += list->n;
		list = list->next;
	}

	return (sum);
}
