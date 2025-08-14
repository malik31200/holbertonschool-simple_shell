#ifndef MY_UTILS_H
#define MY_UTILS_H
#include <stddef.h>

/* --- Utility functions --- */
void *_realloc(void *ptr, size_t old_size, size_t new_size);
void _free_split_string(char **string_arr);
 char *_strchr(const char *str, int c);

#endif /* MY_UTILS_H */
