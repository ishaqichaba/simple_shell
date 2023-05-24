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

/**
 * _print_error_no - prints error number.
 * @i: integer argument
 * Return: string
 */

void _print_error_no(size_t i)
{
	char const digit[] = "0123456789";
	int shifter, count;
	char *p;
	size_t n;

	n = i;
	count = 0;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	p = malloc(count + 1);
	shifter = i;
	do {
		++p;
		shifter /= 10;
	} while (shifter);
	*p = '\0';
	do {
		*--p = digit[i % 10];
		i /= 10;
	} while (i);
	write(STDOUT_FILENO, p, _strlen(p));
	free(p);
}
