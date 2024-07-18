#ifndef simple_shell_h
#define simple_shell_h

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void shell_run(void);

int numcount(char *line);

char *get_command();

char **tokenize_command(char *command);

int execute_command(char **args);

#endif
