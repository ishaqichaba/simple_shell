#include "main.h"

/**
 * _get_buff - gets command and arguments from stdin
 * Return: buffer containing command and arguments
*/

char *_get_buff()
{
	char *buff = NULL;
	size_t n;int i;

	n = 0;
	if (getline(&buff, &n, stdin) == EOF)/*listens to EOF signal*/
	{
		free(buff);
		write(0, "\n", 2);
		_exit(0);
	}
	buff[_strlen(buff) - 1] = '\0';/*Eliminates the new line character set by getline*/
	if(buff[0] == '\0') return NULL;
	for(i = 0; i < _strlen(buff); i++)/*Handles spaces as command*/
		if(buff[i] != ' ') return buff;
	return NULL;
}

/**
 * _set_argv - sets an array of strings containing command and arguments
 * @buff: buffer containing command and arguments to tokenize
 * Return: array of strings containing command and arguments
*/

char **_set_argv(char *buff)
{
	int word_count, buff_lenght, i, j;
	char **argv = NULL;

	word_count = buff_lenght = i = j =0;
	while((buff)[buff_lenght] != '\0') buff_lenght++;
	/*Loop to get the Number of words(strings)*/
	for (i = 0; i < buff_lenght; i++)
	{
		if ((buff)[i] != ' ' && ((buff)[i + 1] == ' ' || ((buff)[i + 1] == '\0'))) word_count++;
	}
	/*Allocating memory for pointer to the words*/
	argv = malloc((word_count + 1) * sizeof(char*));
	argv[0] = strtok(buff, " ");
	i = 1;
	while(i < word_count)
	{
		argv[i] = strtok(NULL, " ");
		i++;
	}
	argv[i] = NULL;
	return argv;
}

/**
 * extract_path - extract PATH variable value from environment
 * Return: buffer containing the value of PATH
*/

char *extract_path()
{
	char *buff = malloc(1024);
	extern char **environ;
	int i;

	i = 0;
	while (environ[i])
	{
		if(environ[i][0] == 'P' && environ[i][1] == 'A' && environ[i][2] == 'T' && environ[i][3] == 'H')
			return(_strcpy_from_n(buff, environ[i], 5));
		i++;
	}
	return NULL;
}

/**
 * _set_path - tokenizes PATH value
 * @path: PATH value
 * Return: buffer containing single paths
*/

char **_set_path(char* path)
{
	int path_count, buff_lenght, i, j;
	char **_storedpaths = NULL;

	path_count = buff_lenght = i = j =0;
	while(path[buff_lenght] != '\0') buff_lenght++;
	/*Loop to get the Number of words(strings)*/
	for (i = 0; i < buff_lenght; i++)
	{
		if (path[i] != ':' && ((path[i + 1] == ':' || path[i + 1] == '\0'))) path_count++;
	}
	/*Allocating memory for pointer to the words*/
	_storedpaths = malloc((path_count + 1) * sizeof(char*));
	_storedpaths[0] = strtok(path, ":");
	i = 1;
	while(i < path_count)
	{
		_storedpaths[i] = strtok(NULL, ":");
		i++;
	}
	_storedpaths[i] = NULL;
	return _storedpaths;
}

/**
 * argv_filter - extracts executable from executable path
 * @path: executable path
 * Return: executable name
*/

char *argv_filter(char* path)
{
	char *store, *store1, *store2, *store3;
	int flag;

	store = _strdup_(path);
	if(!(store1 = strtok(store, "/")))
	{
		free (store);
		return path;
	}
	flag = 0;
	while(1)
	{
		/*printf("in while\n");*/
		if(!(store2 = strtok(NULL, "/")) && flag == 0) return store1;
		else if(!(store2))
		{
			return store3;
		}
		flag = 1;
		if(!(store3 = strtok(NULL, "/")))
		{
			return store2;
		}
	}
}