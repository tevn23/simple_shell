#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_AV 64

/* Function prototypes */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _putchar(char c);
void execute_command(char **av, char **envp);
void tokenize_input(char *input, char **av);


#endif /* MAIN_H */
