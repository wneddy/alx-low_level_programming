#include "hash_tables.h"

/**
 * hash_table_get - function that retrieves a value
 * associated with a key.
 * @ht: hash table to retrieve.
 * @key: key that u are looking for.
 * Return: value associated with element.
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx;
	hash_node_t *currentNode;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);
	idx = key_index((const unsigned char *)key, ht->size);
	currentNode = ht->array[idx];
	while (currentNode != NULL)
	{
		if (strcmp(currentNode->key, key) == 0)
			return (currentNode->value);
		currentNode = currentNode->next;
	}
	return (NULL);
}
