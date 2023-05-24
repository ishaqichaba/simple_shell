#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <dirent.h>


char **_set_path(char *path);
char **_set_argv(char *buff);
char *_get_buff();
char *_strcpy_from_n(char *dest, char *src, int n);
char *argv_filter(char *path);
char *extract_path();
char *_strcat(char *dest, char *src);
char *_strcat_ptr(char **dest, char *src);
char *_strdup_(char *str);
char *_strcpy(char *dest, char *src);
void *_realloc(void **ptr, unsigned int old_size, unsigned int new_size);
int env_exit(char *argv0, char **environ);
int search_cmd(char *argv, char **path_store, int *track);
int search_in_other_dir(char *argv0, int *flag);
int check_path_argv(char *argv0, char **path, int *track, int *flag1);
int _getline(char **lineptr, size_t *n, FILE *stream);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);

#endif /*MAIN_H*/
