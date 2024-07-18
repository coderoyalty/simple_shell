#ifndef simple_shell_h
#define simple_shell_h

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void shell_run(void);

int numcount(char *line);

char *get_command();

char **tokenize_command(char *command);

int execute_command(char **args);

int sh_cd(char **args);
int sh_help(char **args);

static char *builtin_str[] = {
    "cd",
    "help"};

static int (*builtin_func[])(char **) = {
    &sh_cd,
    &sh_help,
};

static int num_builtins()
{
  return sizeof(builtin_str) / sizeof(char *);
}

#endif
