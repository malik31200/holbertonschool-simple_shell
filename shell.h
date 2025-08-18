#ifndef MY_SHELL_H
#define MY_SHELL_H

#define BUFFSIZE 1024

extern char **environ;

char **split_token(char *line);
int lenght_tok(const char *line, const char *delimiter);
int execute_command(char **argv);
void print_env(void);

#endif
