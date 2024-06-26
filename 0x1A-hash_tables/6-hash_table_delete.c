#include "hash_tables.h"

/**
 * hash_table_delete - function that deletes a hash table.
 * @ht: the hash table to be deleted
 *
 * Return: void().
 */

void hash_table_delete(hash_table_t *ht)
{
	unsigned long int a;
	hash_node_t *currentNode, *tempNode;

	if (ht == NULL)
		return;
	for (a = 0; a < ht->size; a++)
	{
		currentNode = ht->array[a];
		while (currentNode != NULL)
		{
			tempNode = currentNode->next;
			free(currentNode->key);
			free(currentNode->value);
			free(currentNode);
			currentNode = tempNode;
		}
	}
	free(ht->array);
	free(ht);
}
