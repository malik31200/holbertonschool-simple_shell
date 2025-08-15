#ifndef MY_SHELL_H
#define MY_SHELL_H

#define BUFFSIZE 1024

extern char **environ;

int execute_nopath(char *line);
int split_arg(const char *line, const char *delimiter);

#endif
