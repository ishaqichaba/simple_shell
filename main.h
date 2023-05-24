#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <dirent.h>

extern char **environ;
char *_get_buff();
int _strlen(char *s);
void _print_error_no(size_t i);
void error_msg(char **argf, char *argv, size_t error_count);

#endif /*MAIN_H*/
