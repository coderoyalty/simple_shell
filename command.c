#include "shell.h"

int numcount(char *line)
{
  int num_tokens = 0;
  int i;
  int is_token = 1; /*the program name is also a token, it's the first token, hence 1.*/
  
  for (i = 0; line[i]; i++)
  {
    if (line[i] == ' ' || line[i] == (char)10 || line[i] == '\t')
    {
      is_token = 1;
    }
    else if (is_token == 1)
    {
      is_token = 0;
      num_tokens++;
    }
  }

  return (num_tokens);
}

char* get_command()
{
  char *line = NULL;
  size_t length = 0;
  
  getline(&line, &length, stdin);

  return line;
}

char** tokenize_command(char* command)
{
  int i = 0;
  char *newline = NULL, *token = NULL, **tokens = NULL;
  int num_tokens = numcount(command);
  char *delimiter = " \t\r\n\f\v";
  
  newline = strdup(command);

  token = strtok(newline, delimiter);

  if (token == NULL)
  {
    free(newline);
    return (tokens);
  }

  tokens = malloc(sizeof(char*) * (num_tokens + 1));

  while (token != NULL)
  {
    tokens[i++] = strdup(token);

    token = strtok(NULL, delimiter);
  }
  tokens[i] = 0;
  free(newline);
  return (tokens);
}

