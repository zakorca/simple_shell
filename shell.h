#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <sys/stat.h>


int execute_cmd(char **tok, char *buff);
char *_getenv(char *name);
char *get_cmd(char *command);
int _strlen(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);
void free_tok(char **tok);
char *_strncpy(char *dest, char *src, int n);
void _puts(char *str);
int _putchar(char c);
int check_spaces_tabs(char *str);
int check_spaces_around_command(char *input);
int builtin_hundler(char **tokens, char *buffer);
int envir_function(void);
int _strcmp(char *s1, char *s2);
int exit_function(char **tokens, char *buffer);
int _strncmp(const char *s1, const char *s2, size_t n);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(char *name);
void tokenize(char *buffer, char **tokens);
int _atoi(char *conv_ptr);

extern char **environ;

void changedir_pwd(char **args);
void chang_dir(char **dir, char *cmd);

#endif
