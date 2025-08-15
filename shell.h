#ifndef MY_SHELL_H
#define MY_SHELL_H

#define BUFFSIZE 1024

extern char **environ;

int split_token(char *line);
int lenght_tok(const char *line, const char *delimiter);

#endif
