#include "lists.h"

/**
 * add_dnodeint_end - function to add new node at the end
 * of list.
 * @head: first node of the list.
 * @n: holding position of the new node.
 *
 * Return: address of the new node.
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *n_node;
	dlistint_t *temp_node = *head;

	if (!head)
		return (NULL);
	n_node = malloc(sizeof(dlistint_t));
	if (!n_node)
		return (n_node);

	n_node->n = n;
	n_node->next = NULL;

	if (*head == NULL)
	{
		n_node->prev = NULL;
		*head = n_node;
		return (n_node);
	}
	while (temp_node->next)
	{
		temp_node = temp_node->next;
	}
	temp_node->next = n_node;
	n_node->prev = temp_node;

	return (n_node);
}
