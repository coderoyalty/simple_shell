#include "shell.h"

int sh_cd(char **args)
{
  if (args == NULL)
  {
    return -1;
  }

  else if (args[1] == NULL)
  {
    fprintf(stderr, "expected argument to \"cd\"\n");
    return -1;
  }

  if (chdir(args[1]) != 0) {
      perror("shell: cd error");
  }

  return 1;
}

int sh_help(char **args)
{
  printf("Code Royalty's Shell\n");
  printf("The following are built in:\n");
  for (int i = 0; i < num_builtins(); i++)
  {
    printf("  %s\n", builtin_str[i]);
  }
  return 1;
}
