#ifndef MY_SHELL_H
#define MY_SHELL_H

#define BUFFSIZE 1024
/* system environement variable */
extern char **environ;

/* --- Shell utilities --- */
int simple_shell(char *command, char *shell_name);

#endif /* MY_SHELL_H */
