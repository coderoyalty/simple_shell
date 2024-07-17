#include "shell.h"
#include <stdio.h>

void shell_run(void)
{
    char* command = NULL;
    char** tokens = NULL;
    int exit_status = 1;
    int i = 0;

    while (exit_status) {
        printf("#aksh$ ");
    
        command = get_command();

        tokens = tokenize_command(command);

        if (strcmp(tokens[0], "exit") == 0)
        {
            exit_status = 0;
        };

        if (tokens != NULL)
        {
            for (i = 0; tokens[i] != NULL; free(tokens[i++]));
            free(tokens);
        }

        if (command) free(command);
    }
}

int main(void)
{
    char* command = NULL;
    char** tokens = NULL;
    int i = 0;
    int exit_status = 0;
    
    while (1)
    {
        if (exit_status == 1)
        {
            exit_status = 0;
            exit(0);
        }
        printf("#aksh$ ");

        command = get_command();

        tokens = tokenize_command(command);

        if (strcmp(tokens[i], "exit") == 0)
        {
            exit_status = 1;
        };

        if (tokens != NULL)
        {
            for (i = 0; tokens[i] != NULL; free(tokens[i++])) ;
            free(tokens);
        }

        if (command) free(command);
    }
}

