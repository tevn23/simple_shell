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
        int i;

	(void)i;

        while (1)
        {
                /* Display prompt */
                printf("simple_shell$ ");
		fflush(stdout);

                /* Read command from user */
                input_length = getline(&input, &input_size, stdin);

                /* Check for End of File (Ctrl+D) */
                if (input_length == -1)
                {
                        _putchar('\n');
                        free(input);
                        exit(EXIT_SUCCESS);
                }

                /* Remove newline character */
                if (input_length > 0 && input[input_length - 1] == '\n')
                        input[input_length - 1] = '\0';

                /* Executing the command */
		av[0] = input;
		av[1] = NULL;

                if (ac > 0)
                        execute_command(av, envp);
        }

        return (0);
}
