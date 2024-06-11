#include "lists.h"

/**
 * insert_dnodeint_at_index - function that adds a node
 * to a specified index.
 * @h: pointer to the list.
 * @idx: index position of the node.
 * @n: data inside the node.
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *n_node, *t_node;
	unsigned int a;

	n_node = malloc(sizeof(dlistint_t));
	if (n_node == NULL)
	{
		return (NULL);
	}
	n_node->n = n;
	n_node->prev = NULL;
	n_node->next = NULL;
	if (idx == 0)
	{
		n_node->next = *h;
		if (*h != NULL)
			(*h)->prev = n_node;
		*h = n_node;
		return (n_node);
	}
	t_node = *h;
	for (a = 0; t_node != NULL && a < idx - 1; a++)
	{
		t_node = t_node->next;
	}
	if (t_node == NULL || (t_node->next == NULL && a + 1 != idx))
	{
		free(n_node);
		return (NULL);
	}
	n_node->next = t_node->next;
	n_node->prev = t_node;
	if (t_node->next != NULL)
	{
		t_node->next->prev = n_node;
	}
	t_node->next = n_node;
	return (n_node);
}
