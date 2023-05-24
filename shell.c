#include "main.h"

/**
 * main - launches shell
 * Return: void
*/

int main(void)
{
	char *command = NULL;
	char **argv = NULL;
	int n;

	while (1)
	{
		write(1, "SALAFI SHELL Enter cmd$ ", 24);
		command = _get_buff();
		if (command == NULL)
			continue;
		if (fork() == 0)
		{
			if (execve(command, argv, environ) < 0)
			{
				perror(command);
				free(command);
				exit(EXIT_FAILURE);
			}
		}
	wait(&n);
	}
	return (0);
}