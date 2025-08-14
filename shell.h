#ifndef MY_SHELL_H
#define MY_SHELL_H

#define BUFFSIZE 1024
/* system environement variable */
extern char **environ;

/* --- Shell utilities --- */
int simple_shell(char *command, char *shell_name);

/* --- command execution function --- */
int execute_command(char *command, char **commands);
int execute_no_path(char **commands, char *shell_name);
int execute_path(char **commands, char *shell_name);
int execute_command(char *command, char **commands);

/* --- command built-in --- */
int builtin_env(char **argv);
int run_builtins(char **commands, int *status);

#endif /* MY_SHELL_H */
