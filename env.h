#ifndef MY_ENV_H
#define MY_ENV_H

/* system variable environ */
extern char **environ;

/* --- environ utilities --- */
char **get_env(void);
char *get_env_var(const char *var);
char *path_finder(void);
void free_char_arr(char **str);

#endif /* MY_ENV_H */
