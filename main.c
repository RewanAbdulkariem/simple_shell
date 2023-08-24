#include "main.h"
/**
 * main - the entry
 * Return: 0 on success
 */
int main(void)
{
	char **argv;
	char *cmd = NULL;
	size_t n = 0;
	char InternalCmd = 0;			/*flag to indicate the command is built-in or not*/
	char* built_in[4] = {"cd", "export", "echo","exit"};
	int i;

	while (1)
	{
		printf("SHELL# ");

		if (getline(&cmd, &n, stdin) == -1)
		{
			free(cmd);
			printf("\n");
			return(-1);
		}
		argv = parse_line(cmd);
		for (i = 0; i < 4; i++)
		{
			if (!strcmp(argv[0],built_in[i]))   
           		 {
                		InternalCmd = 1;            
                		break;                 
            		}
            		else
                		InternalCmd = 0;
		}
		if (InternalCmd == 1)
			shellBultin(argv);
		else
			excute_command(argv);
	}
	free(cmd);
	free(argv);
	return (0);
}
