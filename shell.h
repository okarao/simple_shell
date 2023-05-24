#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define TOKEN_DELIMITER " \t\r\n\a"
extern char **environ;

char *read_line();
char **split_line(char *line);
void execute_command(char **args);
int handle_builtin(char **args);
void shell_loop();
int main();

#endif /* SHELL_H */

