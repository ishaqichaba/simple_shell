#include "main.h"

/**
 * _strcpy_from_n - Copies string from src to dest starting from nth member of src
 * @dest: destination
 * @src: source
 * @n: starting point
 * Return: pointer to dest
*/

char *_strcpy_from_n(char *dest, char *src, int n)
{
    int i;

    i = 0;
	while(*(src + n) != '\0')
	{
		*(dest + i) = *(src + n);
		n++;
        i++;
	}
	*(dest + i) = '\0';

	return(dest);
}

/**
 * _strcpy - copy contents of src to  dest.
 * @dest: char pointer(destination).
 * @src: char pointer(Source)
 * Return: Pointer
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while(*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';

	return(dest);
}

/**
 * _strlen - returns the length of a string.
 * @s: A string pointer
 * Return: length of a string
 */

int _strlen(char *s)
{
	int count, i;

	count = i = 0;
	while(*(s + i) != '\0')
	{
		count++;
		i++;
	}

	return (count);
}

/**
 * _strcat - concatenates two strings.
 * @dest: char pointer argument (String to be added to)
 * @src: char pointer argument (string to be added)
 * Return: pointer to char(concatenated string)
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	i = j = 0;
	while(*(dest + i) != '\0')
	{
		i++;
	}
	while (*(src + j) != '\0')
	{
		*(dest + i) = *(src + j);
		i++;
		j++;
	}
	*(dest + i) = *(src + j);

	return dest;
}

/**
 * _strcmp - copies a string.
 * @s1: char pointer
 * @s2: char pointer
 * Return: 0 if s1 and s2 equal ,+ve or -ve otherwise
 */

int _strcmp(char *s1, char *s2)
{
	int i, j;

	i = j = 0;
	while(*(s1 + i) != '\0')i++;
	while(*(s2 + j) != '\0')j++;
	if(i > j) return 1;
	else if(j > i) return -1;
	i = 0;
	while(*(s1 + i) != '\0')
	{
		if(s1[i] != s2[i]) return 1;
		i++;
	}
	i = 0;
	while(*(s2 + i) != '\0')
	{
		if(s2[i] != s1[i]) return 1;
		i++;
	}
	return (0);
}
