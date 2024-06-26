#include "hash_tables.h"

/**
 * shash_table_create - function that creates a hash table.
 * @size: size of the array.
 *
 * Return: pointer to the newly created hash table.
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *hash_t;
	unsigned long int a;

	hash_t = malloc(sizeof(shash_table_t));

	if (hash_t == NULL)
		return (NULL);
	hash_t->size = size;
	hash_t->array = malloc(sizeof(shash_node_t *) * size);
	if (hash_t->array == NULL)
	{
		free(hash_t);
		return (NULL);
	}
	for (a = 0; a < size; a++)
		hash_t->array[a] = NULL;
	hash_t->shead = NULL;
	hash_t->stail = NULL;
	return (hash_t);
}
/**
 * shash_table_set - function that adds an element to the hash
 * table.
 * @ht: hash  table to add the element.
 * @key: key that will rep the element.
 * @value: value to be casted into the element.
 * Return: hash table with the element added.
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *n_node, *currentNode, *prev = NULL;
	unsigned long int idx;
	char *copyValue;

	if (ht == NULL || key == NULL || strlen(key) == 0 || value == NULL)
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
	n_node = malloc(sizeof(shash_node_t));
	if (n_node == NULL)
	{
		free(copyValue);
		return (0);
	}
	n_node->key = strdup(key);
	if (n_node->key == NULL)
	{
		free(n_node);
		return (0);
	}
	n_node->value = copyValue;
	n_node->next = ht->array[idx];
	ht->array[idx] = n_node;
	if (ht->shead == NULL || strcmp(key, ht->shead->key) < 0)
	{
		n_node->next  = ht->shead;
		n_node->sprev = NULL;
		if (ht->shead != NULL)
			ht->shead->sprev = n_node;
		ht->shead = n_node;
		if (ht->stail == NULL)
			ht->stail = n_node;
	}
	else
	{
		currentNode = ht->shead;
		while (currentNode != NULL && strcmp(key, currentNode->key) > 0)
		{
			prev = currentNode;
			currentNode = currentNode->snext;
		}
		n_node->snext = currentNode;
		n_node->sprev = prev;
		if (currentNode != NULL)
			currentNode->sprev = n_node;
		else
			ht->stail = n_node;
		if (prev != NULL)
			prev->snext = n_node;
	}
	return (1);
}
/**
 * shash_table_get - function that retrieves a value
 * associated with a key.
 * @ht: hash table to retrieve.
 * @key: key that u are looking for.
 * Return: value associated with element.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int idx;
	shash_node_t *currentNode;

	if (ht == NULL || key == NULL || strlen(key) == 0)
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
/**
 * shash_table_print - function that prints a hash table.
 * @ht: hash table to printed.
 * Return: the printed ht.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *currentNode;
	int first = 1;

	if (ht == NULL)
		return;
	printf("{");
	currentNode = ht->shead;
	while (currentNode != NULL)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", currentNode->key, currentNode->value);
		first = 0;
		currentNode = currentNode->next;
	}
	printf("}\n");
}
/**
 * shash_table_print_rev - function that print hash table in reverse.
 * @ht: hash table.
 * Return: printed rev ht.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *currentNode;
	int first = 1;

	if (ht == NULL)
		return;
	printf("{");
	currentNode = ht->stail;
	while (currentNode != NULL)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", currentNode->key, currentNode->value);
		first = 0;
		currentNode = currentNode->sprev;
	}
	printf("}\n");
}
/**
 * shash_table_delete - function that deletes a hash table.
 * @ht: the hash table to be deleted
 * Return: void().
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int a;
	shash_node_t *currentNode, *tempNode;

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
