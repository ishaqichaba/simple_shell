#include "main.h"

/**
 * search_cmd - searces for command in PATH
 * @command: buffer from stdin
 * @path_store: tokenized PATH variable
 * @track: path_store tracker
 * Return: 0 if found 1 otherwise
*/
int search_cmd(char *command, char **path_store, int *track)
{
	DIR *direct;
	struct dirent *file;

	*track = 0;
	while (path_store[*track])
	{
		if (!(direct = opendir(path_store[*track]))) return 1;
		/*printf("%s\n", buff); */
		while ((file = readdir(direct)))
		{
			if (_strcmp(file->d_name, command) == 0)
			{
				closedir(direct);
				return (0);
			}
		}
		closedir(direct);
		(*track)++;
	}
	return (1);
}

/**
 * check_path_argv - generally searches for command
 * @argv0: executable path
 * @path: tokenized PATH variable
 * Return: 0 if found 1 otherwise
*/

int check_path_argv(char *argv0, char **path, int *track, int *flag)
{
	char *temp;
	#define CMP2 _strcmp(argv0, _strcat_ptr(&temp, argv_filter(argv0))) == 0
	#define CMP1 (*flag = _strcmp(argv0, argv_filter(argv0))) == 0
	*flag = 0;
	if (!(search_cmd(argv_filter(argv0), path, track)))
	{
		temp = _strdup_(path[*track]);
		_strcat_ptr(&temp, "/");
		if (CMP1 || CMP2)
		{
			free(temp);
			return (0);
		}
		free(temp);
	}
	if (!search_in_other_dir(argv0, flag))
		return (0);
	return (1);
}

/**
 * search_in_other_dir - searches for executable outside PATH variable
 * @argv0: executable path
 * Return: 0 if found 1 otherwise
 */

int search_in_other_dir(char *argv0, int *flag)
{
	char *path;
	char *buff = NULL;
	DIR *direct;
	struct dirent *file;

	*flag = 1;
	if (!_strcmp(argv0, argv_filter(argv0)))
	{
		path = getcwd(buff, 256);
		goto E;
	}
	path = _strdup_(argv0);
	path[_strlen(path) - _strlen(argv_filter(argv0)) - 1] = '\0';
	if (!_strcmp(path, "."))
	{
		free(path);
		path = getcwd(buff, 256);
	}
E:
	if ((direct = opendir(path)) == NULL)
	{
		closedir(direct);
		free(path);
		return (1);
	}
	while ((file = readdir(direct)))
	{
		if (_strcmp(argv_filter(argv0), file->d_name) == 0)
		{
			closedir(direct);
			free(path);
			return (0);
		}
	}
	closedir(direct);
	free(path);
	return (1);
}