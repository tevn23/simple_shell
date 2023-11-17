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
