#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <stddef.h>
#include <errno.h>

extern char **environ;
char *read_input_line(char **lineptr, size_t *n);
char **tokenize_input(char *line, int *size);
void execute_command(char **array, char *program_name);
void handle_args(int ac, char **av);
char *find_command_in_path(const char *command);
int check_exit(char **array);
void handle_env(void);
void _printf(const char *format, ...);
void pr_str(va_list args);
void print_int(int value);
int _puts(const char *str);
int _snprintf(char *str, size_t size, const char *format, ...);
int append(char *buf, size_t size, const char *src);
int append_int(char *buf, size_t size, int value);
int _putchar(char c);
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *src);
size_t _strlen(const char *l);
void print_integer(va_list args);


#endif /* MAIN_H */

