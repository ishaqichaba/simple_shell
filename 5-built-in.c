#include "main.h"

int env_exit(char *argv0, char **environ)
{
    int i;

    i = 0;
    if(!strcmp(argv0, "env"))
    {
        while(environ[i])
        {
            printf("%s\n", environ[i++]);
        }
        return 0;
    }
    else if(!strcmp(argv0, "exit"))
    {
        exit(EXIT_SUCCESS);
    }
    return 1;
}