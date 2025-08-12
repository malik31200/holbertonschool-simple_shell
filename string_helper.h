#ifndef MY_STRING_H
#define MY_STRING_H
#include <stddef.h>

/* --- string utilities --- */
int _strcmp(char *str1, char *str2);
size_t _strlen(char *str);
char *_strdup(char *str);
char **split_string(char *str, char *delimiter);

#endif /* MY_STRING_H */
