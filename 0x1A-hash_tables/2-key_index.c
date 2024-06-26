#include "hash_tables.h"

/**
 * key_index - function that implements the hash_dj2
 * algorithm to find index of a key.
 * @key: get key.
 * @size: size of the array of the hash table.
 *
 * Return: index at which the key/value is stored
 *          in the array of the hash table.
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
