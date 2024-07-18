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

char *get_command()
{
  char *line = NULL;
  size_t length = 0;

  getline(&line, &length, stdin);

  return line;
}

char **tokenize_command(char *command)
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

  tokens = malloc(sizeof(char *) * (num_tokens + 1));

  while (token != NULL)
  {
    tokens[i++] = strdup(token);

    token = strtok(NULL, delimiter);
  }
  tokens[i] = 0;
  free(newline);
  return (tokens);
}

int execute_command(char **args)
{
  pid_t pid, wpid;
  int status;

  if (args[0] == NULL)
  {
    // nothing to run.
    return 1;
  }

  for (int i = 0; i < num_builtins(); i++)
  {
    if (strcmp(args[0], builtin_str[i]) == 0)
    {
      return (*builtin_func[i])(args);
    }
  }

  pid = fork();
  if (pid == 0)
  {
    if (execvp(args[0], args) == -1)
    {
      perror("shell error");
    }
    exit(EXIT_FAILURE);
    return 0;
  }
  else if (pid < 0)
  {
    perror("fork(...) error");
    exit(EXIT_FAILURE);
    return 0;
  }
  else
  {
    do
    {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}
