#ifndef MAIN_H
#define MAIN_H

/*---LIBRARIES---*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

/*---PROTOTYPES---*/
char **parse_string(char *cmd, int num_chars);
void excute_command(char *command, char **argv);
char *command_path(char *command);
void print_environment(void);

#endif
