#include "shell.h"

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

	while (1)
	{
		printf("simple_shell$ ");
		input_length = getline(&input, &input_size, stdin);
		if (input_length == -1)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		if (input_length > 0 && input[input_length - 1] == '\n')
			input[input_length - 1] = '\0';
		av[0] = input;
		av[1] = NULL;
		if (ac > 1)
		{
			for (i = 1; i < ac; i++)
			{
				av[0] = av[i];
				av[1] = NULL;
			}
		}
		else
			execute_command(av, envp);
	}
	return (0);
}
