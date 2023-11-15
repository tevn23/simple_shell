#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_AV 64

/**
 * execute_command - Executes the given command using fork and execve
 * @av: Array of strings containing the command and its arguments
 * @envp: Array of strings containing environment variables
 */
void execute_command(char **av, char **envp)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error forking");
		exit(EXIT_FAILURE);
	}

	else if (pid == 0)
	{
		/* Child process */
		if (execve(av[0], av, envp) == -1)
		{
			perror("Error executing command");
			exit(EXIT_FAILURE);
		}
	}

	else
	{
		/* Parent process */
		/* Wait for the child process to complete */
		waitpid(pid, NULL, 0);
	}
}

/**
 * tokenize_input - Tokenizes input string to extract command and arguments
 * @input: Input string containing the command and its arguments
 * @av: Array of strings to store the tokenized command and arguments
 */

void tokenize_input(char *input, char **av)
{
	int ac = 0;
	char *token;

	token = strtok(input, " ");
	while (token != NULL && ac < MAX_AV - 1)
	{
		av[ac++] = strdup(token);
		token = strtok(NULL, " ");
	}
	av[ac] = NULL;
}

/**
 * main - Entry point, reads user input, tokenizes it, and executes commands
 * @ac: Number of command-line arguments
 * @av: Array of strings containing command-line arguments
 * @envp: Array of strings containing environment variables
 * Return: Always 0
 */
int main(int ac, char **av, char **envp)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t input_length;
	int i;

	while (1)
	{
		/* Display prompt */
		printf("simple_shell> ");
		fflush(stdout);

		/* Read command from user */
		input_length = getline(&input, &input_size, stdin);

		/* Check for End of File (Ctrl+D) */
		if (input_length == -1)
		{
			printf("\n");
			free(input);
			exit(EXIT_SUCCESS);
		}

		/* Remove newline character */
		if (input_length > 0 && input[input_length - 1] == '\n')
			input[input_length - 1] = '\0';

		tokenize_input(input, av);

		if (ac > 0)
			execute_command(av, envp);

		/* Free arguments memory */
		for (i = 0; av[i] != NULL; i++)
			free(av[i]);
	}

	return (0);
}
