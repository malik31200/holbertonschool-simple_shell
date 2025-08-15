#include "shell.h"
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int lenght_tok(const char *line, const char *delimiter);

/**
 * 
 */
int execute_nopath(char *line)

{
    char **argv = NULL;
    char *tok, *copy;
    int i = 0;
    int n;

    if (line == NULL || *line == '\0')
        return (0);
    
    n = lenght_tok(line, " \t");
    if (n <= 0)
        return (0);

    argv = malloc((n + 1) * sizeof(char *));
    if (argv == NULL)
    {
        perror ("malloc failed");
        return (-1);
    }
    copy = strdup(line);
    if (copy == NULL)
    {
        free(argv);
        return (-1);
    }
        
    tok = strtok(copy, " \t");
    for (i = 0; tok != NULL; i++)
    {
        argv[i] = strdup(tok);
        if (argv[i]  == NULL)
            {
                while (i > 0)
                {
                    i--;
                    free(argv[i]);
                    free(copy);
                    return (-1);
                }
            }
            tok = strtok(NULL, " \t");
    }
    argv[i] = NULL;
    free(copy);
    return(0);
}

/**
 * 
 */
int lenght_tok(const char *line, const char *delimiter)
{
    int i = 0;
    char *copy, *token;

    if (line == NULL || *line == '\0' ||
        delimiter == NULL || *delimiter == '\0')
            return (0);

    copy = strdup(line);
    if (copy == NULL)
        return (-1);
    
    token = strtok(copy, delimiter);
    while (token != NULL)
    {
        i++;
        token = strtok(NULL, delimiter);
    }
    free(copy);
    return (i);
}