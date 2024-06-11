#include "lists.h"

/**
 * add_dnodeint - function to add new at the beginning
 * of list.
 * @head: pointer pointing to the head of the list
 * @n: position of the new node to insert.
 *
 * Return: address of the new element.
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *n_node;

	/* assigning the new node space */
	n_node = malloc(sizeof(dlistint_t));
	if (n_node == NULL)
		return (NULL);
	/* positioning the new node */
	n_node->n = n;
	n_node->prev = NULL;
	/* check conditions of head */
	if (*head != NULL)
		(*head)->prev = n_node;
	/* place the new node*/
	n_node->next = *head;
	*head = n_node;

	return (n_node);
}

