#include "main.h"

/**
 * error_msg - Prints error message like sh does
 * @error_count: Error number
 * @argf: argv of shell
 * @argv0: command
 * Return: void
*/
void error_msg(char **argf, char *argv0, size_t error_count)
{
	write(STDOUT_FILENO, argf[0], _strlen(argf[0]));
	write(STDOUT_FILENO, ": ", 2);
	_print_error_no(error_count);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, argv0, _strlen(argv0));
	write(STDOUT_FILENO, ": not found\n", 13);
}
