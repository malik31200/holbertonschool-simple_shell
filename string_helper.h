#ifndef MY_STRING_H
#define MY_STRING_H
#include <stddef.h>

/* --- string utilities --- */
int _strcmp(char *str1, char *str2);
size_t _strlen(const char *str);
char *_strdup(char *str);
char **split_string(char *str, char *delimiter);
int _strncmp(char *str1, char *str2, size_t n);
char *_strcat(const char *src, char *dest);

#endif /* MY_STRING_H */
