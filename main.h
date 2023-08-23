#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stddef.h>
#include <limits.h>

char **parse_line(char *line);
void excute_command(char **argv);

#endif
