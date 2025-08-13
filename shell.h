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

/* --- builtins utilities --- */
int run_builtins(char *command);

#endif /* MY_SHELL_H */
