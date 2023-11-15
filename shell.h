#ifndef SHELL_H
#define SHELL_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdbool.h>



extern char **envir;


int execute_cmd(char **avv, char *buf);
char *_getenv(char *name);
int _strncmp(const char *s1, const char *s2, size_t n);
char *get_cmd(char *command);
int _strlen(char *str);
char *_strcat(char *desti, char *sourc);
int env_func(void);
int _check_space_tab(char *str);
char *_strcpy(char *desti, char *sourc);
char *_strdup(char *str);
char *_memcpy(char *desti, char *sourc, unsigned int n);
void free_avv(char **avv);
char *_strncpy(char *desti, char *sourc, int n);
void _puts(char *str);
int _putchar(char c);
int check_spaces_around_cmd(char *input);
int handle_builtin_(char **tokens, char *buffer);
int _strcmp(char *s1, char *s2);
int exit_func(char **tokens, char *buffer);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(char *name);
void tokenize(char *buffer, char **tokens);
int _atoi(char *nptr);

#endif
