#include "main.h"

int _getline(char **lineptr, size_t *n, FILE *stream)
{
    static size_t track = 0;
    int store = 0;
    size_t i = 0;
    *n = 150;

    lseek(stream->_fileno, track, 0);
    *lineptr = malloc(1024);
    store = read(stream->_fileno, *lineptr, *n);
    /*printf("%s\n", *lineptr);*/
    if(store == 0)
    {
        return 0;
    }
    while((*lineptr)[i] != '\n')
    {
        if((*lineptr)[i] == '\0')
        {
            break;
        }
        i++;
    }
    if((*lineptr)[i] != '\0') (*lineptr)[i + 1] = '\0';
    else
    {
        (*lineptr)[i] = '\n';
        /*(*lineptr)[i + 1] = '\0';*/
    }
    track += strlen(*lineptr);
    return (strlen(*lineptr));
}