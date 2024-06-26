#include "hash_tables.h"

/**
 * hash_table_print - function that prints a hash table.
 * @ht: hash table to printed.
 * Return: the printed ht.
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int a;
	hash_node_t *currentNode;
	int first = 1;

	if (ht == NULL)
		return;
	printf("{");
	for (a = 0; a < ht->size; a++)
	{
		currentNode = ht->array[a];
		while (currentNode != NULL)
		{
			if (!first)
				printf(", ");
			printf("'%s': '%s'", currentNode->key, currentNode->value);
			first = 0;
			currentNode = currentNode->next;
		}
	}
	printf("}\n");
}
