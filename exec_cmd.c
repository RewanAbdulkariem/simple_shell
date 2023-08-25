#include "main.h"

void execmd(char **argv)
{
    pid_t pid;

    if (argv)
    {
        pid = fork();

        if (pid == -1)
        {
            perror("Error: fork failed");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            /* Child process */
            if (execve(argv[0], argv, NULL) == -1)
            {
                perror("Error: execve failed");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            /* Parent process */
            int status;
            if (waitpid(pid, &status, 0) == -1)
            {
                perror("Error: waitpid failed");
                exit(EXIT_FAILURE);
            }
        }
    }
}

