#include "main.h"

/**
 * _get_buff - gets command and arguments from stdin
 * Return: buffer containing command and arguments
*/

char *_get_buff()
{
    static char *buff = NULL;
    size_t n;
    int i;
    static int flag = 0;
    
    printf("%d\n", flag);
    if (flag > 0)
        free(buff);
    flag++;
    n = 0;
    if (getline(&buff, &n, stdin) == EOF)/*listens to EOF signal*/
    {
        free(buff);
        write(0, "\n", 2);
        _exit(0);
    }
    buff[_strlen(buff) - 1] = '\0';/*Eliminates the new line character set by getline*/
    if (buff[0] == '\0') 
        return (NULL);
    for (i = 0; i < _strlen(buff); i++)/*Handles spaces as command*/
    {
        if (buff[i] != ' ')
            return (buff);
    }
    return (NULL);
}