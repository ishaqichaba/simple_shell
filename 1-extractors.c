#include "main.h"

/**
 * _get_buff - gets command and arguments from stdin
 * Return: buffer containing command and arguments
*/

char *_get_buff()
{
	static char *buff;
	size_t n;
	int i;
	static int flag = 1;

	if (flag > 1)
		free(buff);
	flag++;
	n = 0;
	if (getline(&buff, &n, stdin) == EOF)/*listens to EOF signal*/
	{
		free(buff);
		write(STDOUT_FILENO, "\n", 2);
		exit(EXIT_SUCCESS);
	}
	/*Eliminates the new line character set by getline*/
	buff[_strlen(buff) - 1] = '\0';
	if (_strlen(buff) > 4095)
		buff[4095] = '\0';
	if (buff[0] == '\0')
		return (NULL);
	for (i = 0; i < _strlen(buff); i++)/*Handles spaces as command*/
	{
		if (buff[i] != ' ')
			return (buff);
	}
	return (NULL);
}
