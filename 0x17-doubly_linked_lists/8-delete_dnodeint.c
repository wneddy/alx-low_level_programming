#include "lists.h"

/**
 * delete_dnodeint_at_index - function to delete a node
 * at specified index position.
 * @head: pointer to the head of the list.
 * @index: index position of the node to be deleted.
 *
 * Return: 1 for success/ -1 for failed.
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *t_node;
	unsigned int a;

	if (head == NULL || *head == NULL)
		return (-1);

	t_node = *head;

	if (index == 0)
	{
		*head = t_node->next;
		if (*head != NULL)
		{
			(*head)->prev = NULL;
		}
		free(t_node);
		return (1);
	}
	for (a = 0; t_node != NULL && a < index; a++)
	{
		t_node = t_node->next;
	}
	if (t_node == NULL)
		return (-1);
	if (t_node->next != NULL)
	{
		t_node->next->prev = t_node->prev;
	}
	if (t_node->prev != NULL)
	{
		t_node->prev->next = t_node->next;
	}
	free(t_node);
	return (1);
}
