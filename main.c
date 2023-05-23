#include "main.h"

#define ERROR_MSG                        \
	write(0, "./shell: ", 9);            \
	write(0, argv[0], _strlen(argv[0])); \
	write(0, " is not a command or file.\n", 28);

int main(void)
{
    extern char **environ; char **argv = NULL, **argp = NULL; char *command = NULL, *temp = NULL, *path_value = NULL;
	int n, flag, flag1, track;

    path_value = extract_path(); argp = _set_path(path_value);
    while (1)
    {
        flag = 0;
        write(1, "SALAFI SHELL Enter cmd$ ", 24);
        if(!(command = _get_buff())) continue;
        argv = _set_argv(command);
        if(!env_exit(argv[0], environ)) continue;
        if(check_path_argv(argv[0], argp, &track, &flag1))
		{
            flag = 1; goto E;
		}
        if(fork() == 0)
        {
            if(!flag1)
			{
                temp = _strdup_(argp[track]); _strcat(temp, "/"); argv[0] = _strcat(temp, argv[0]);
			}
            if(execve(argv[0], argv, environ) < 0)
			{
                perror(argv[0]); free(argv) exit(1);
			}
        }
        wait(&n);
E:
        if(flag == 1) ERROR_MSG
        free(argv); free(command);
    }
    free(argp); free(path_value); return 0;
}