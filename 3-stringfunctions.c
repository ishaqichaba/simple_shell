#include "main.h"

/**
 * _strlen - returns the length of a string.
 * @s: A string pointer
 * Return: length of a string
 */

int _strlen(char *s)
{
	int count, i;

	count = i = 0;
	while (*(s + i) != '\0')
	{
		count++;
		i++;
	}
	return (count);
}
