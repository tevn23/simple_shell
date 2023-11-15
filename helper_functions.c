#include "shell.h"

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

