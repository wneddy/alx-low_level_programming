#include "lists.h"

/**
 * free_dlistint - function frees dlistint
 * @head: pointer to the list.
 *
 * Return: no list.
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *list;

	while (head != NULL)
	{
		list = head;
		head = head->next;
		free(list);
	}
}
