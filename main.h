#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <dirent.h>
#include <errno.h>
#include <error.h>

extern char **environ;
char *_get_buff();
int _strlen(char *s);
void _print_error_no(size_t i);

#endif /*MAIN_H*/
