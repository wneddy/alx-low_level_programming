#include "hash_tables.h"

/**
 * hash_table_set - function that adds an element to the hash
 * table.
 * @ht: hash  table to add the element.
 * @key: key that will rep the element.
 * @value: value to be casted into the element.
 * Return: hash table with the element added.
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *n_node, *currentNode;
	unsigned long int idx;
	char *copyValue;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	copyValue = strdup(value);
	if (copyValue == NULL)
		return (0);
	idx = key_index((const unsigned char *)key, ht->size);
	currentNode = ht->array[idx];
	while (currentNode != NULL)
	{
		if (strcmp(currentNode->key, key) == 0)
		{
			free(currentNode->value);
			currentNode->value = copyValue;
			return (1);
		}
		currentNode = currentNode->next;
	}
	n_node = malloc(sizeof(hash_node_t));
	if (n_node == NULL)
	{
		free(copyValue);
		return (0);
	}
	n_node->key = strdup(key);
	if (n_node->key == NULL)
	{
		free(n_node);
		free(copyValue);
		return (0);
	}
	n_node->value = copyValue;
	n_node->next = ht->array[idx];
	ht->array[idx] = n_node;
	return (-1);
}
