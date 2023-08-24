#include "main.h"
void shellBultin(char **argv)
{
	char *cwd;
	int i;
	
	if (strcmp(argv[0], "cd") == 0)
	{
		if (argv[1] == NULL || !strcmp(argv[1], "~"))
			cwd = "/home";
		else
			cwd = argv[1];
		chdir(cwd);
	}
	else if (strcmp(argv[0], "echo") == 0)
	{
		for (i = 1; argv[i] != NULL; i++)
		{
			printf("%s", argv[i]);
			if (argv[i + 1] != NULL)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	else if (strcmp(argv[0], "export") == 0)
	{
		
	}
	else if (strcmp(argv[0], "exit") == 0)
	{
		_exit(0);
	}
}
