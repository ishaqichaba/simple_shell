#include "main.h"
/**
 * mySig - handles ctrl+C
 * @signum: Signal type
 * Return: void
*/

void mySig(int signum)
{
	(void)signum;
	write(STDOUT_FILENO, "\n", 2);
	write(1, "SALAFI SHELL Enter cmd$ ", 24);
}

/**
 * main - launches shell
 * @argc: No of args
 * @argf: arguments to main
 * Return: void
*/

int main(int argc, char **argf)
{
	char *command = NULL;
	char **argv = NULL;
	int n;
	size_t error_count;

	(void)argc;
	error_count = 0;
	while (1)
	{
		signal(SIGINT, mySig);
		++error_count;
		if (isatty(STDIN_FILENO))
			write(1, "SALAFI SHELL Enter cmd$ ", 24);
		command = _get_buff();
		if (command == NULL)
			continue;
		if (fork() == 0)
		{
			if (execve(command, argv, environ) < 0)
			{
				perror(argf[0]);
				free(command);
				exit(EXIT_FAILURE);
			}
		}
	wait(&n);
	}
	return (0);
}
