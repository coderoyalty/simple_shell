#include "shell.h"
#include <stdio.h>

void shell_run(void)
{
    char *command = NULL;
    char **tokens = NULL;
    int exit_status = 1;
    int i = 0;

    do
    {
        printf("#aksh$ ");

        command = get_command();

        if (numcount(command) == 0)
        {
            if (command)
                free(command);
            continue;
        }

        tokens = tokenize_command(command);

        if (strcmp(tokens[0], "exit") == 0)
        {
            exit_status = 0;
        }
        else
        {
            exit_status = execute_command(tokens);
        }

        if (tokens != NULL)
        {
            for (i = 0; tokens[i] != NULL; free(tokens[i++]))
                ;
            free(tokens);
        }

        if (command)
            free(command);
    } while (exit_status);
}

int main(void)
{
    shell_run();

    return 0;
}
