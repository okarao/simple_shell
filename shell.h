#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

char *shell_name;
extern char **environ;


#define BUFFER_SIZE 1024
/* Function Prototypes */
void run_shell(void);
void execute_command(char *command);
int _printenv(void);
char *_strdup(const char *string);
int cmd_read(char *s, size_t __attribute__((unused)) file_stream);
char *pathfinder(char *cmd);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *dest, const char *src);
size_t _strlen(const char *s);
void print_not_found(char *cmd);
int call_command(char *cmd_arr[]);
char *_getenv(char *var);
int _str_n_cmp(char *s1, char *s2, int n);

#endif /* SHELL_H */

