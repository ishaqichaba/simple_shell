#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory, which contains a copy of the string given as a parameter.
 * @str: char pointer
 * Return: Char pointer
 */

char *_strdup_(char *str)
{
	int i, j;
	char *buff;

	i = 0;
	if (str == NULL) return NULL;
	i = _strlen(str);
	buff = malloc(i + 1);
	if (buff == NULL) return NULL;
	for (j = 0; j < i; j++)
	{
		*(buff + j) = *(str + j);
	}
    buff[i] = '\0';
	return (buff);
}

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: old pointer
 * @old_size: old size
 * @new_size: new_size
 * Return:  pointer
 */

void *_realloc(void **ptr, unsigned int old_size, unsigned int new_size)
{
	void *ptr_new;
	int i, size;

	i = 0, size = old_size;
	if(old_size > new_size) size = new_size;
	if (new_size == old_size) return (*ptr);
	if (*ptr == NULL)
	{
		*ptr = malloc(new_size);
		return (*ptr);
	}
	if (new_size == 0 && *ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	ptr_new = malloc(new_size);
	while (i < size)
	{
		*((char *)ptr_new + i) = *((char *)*ptr + i);
		i++;
	}
	free(*ptr);
	*ptr = ptr_new;
	return (*ptr);
}

char *_strcat_ptr(char **dest, char *src)
{
	int i, j;
	/*char *new = malloc(strlen(dest) + strlen(src) + 1);*/
	_realloc((void **)dest, _strlen(*dest), _strlen(*dest) + _strlen(src) + 1);

	i = j = 0;

	while(*(*dest + i) != '\0')
	{
		/*new[i] = dest[i];*/
		i++;
	}
	while (*(src + j) != '\0')
	{
		*(*dest + i) = *(src + j);
		i++;
		j++;
	}
	*(*dest + i) = *(src + j);

	return *dest;
}

int _getline(char **lineptr, size_t *n, FILE *stream)
{
    static size_t track = 0;
    size_t i, store;

    i = store = 0;
    *n = 120;
    lseek(stream->_fileno, track, 0);
    *lineptr = malloc(120);
    store = read(stream->_fileno, *lineptr, *n);
    if(store == 0) return EOF;
    while((*lineptr)[i] != '\n')
    {
        if((*lineptr)[i++] == '\0') break;
    }
    if((*lineptr)[i] != '\0') (*lineptr)[i + 1] = '\0';
    else
    {
        (*lineptr)[i] = '\n';
    }
    track += strlen(*lineptr);
    return (strlen(*lineptr));
}