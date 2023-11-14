#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

/**
 * main - Simple UNIX command line interpreter
 *
 * Description: This program creates a simple shell that accepts single-word
 * commands and executes them. It prompts the user for input, executes the
 * entered command (or simulates execution by echoing), and exits upon entering
 * the 'exit' command or encountering the end-of-file condition (Ctrl+D).
 *
 * Return: Always 0
 */
int main(void)
{
	char input[MAX_INPUT_SIZE]; /* Buffer to hold user input */
	ssize_t read_bytes; /* Variable to store the number of bytes read */

	while (1)
	{
		/* Displaying prompt and flushing output */
		printf("simple_shell> ");
		fflush(stdout);
		
		/* Reading user input from standard input */
		read_bytes = read(STDIN_FILENO, input, MAX_INPUT_SIZE);

		/* Checking for end-of-file condition */
		if (read_bytes == 0)
		{
			printf("\n");
			break;
		}
		
		/* Handling read error */
		if (read_bytes == -1)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}
		
		/* Handling newline character in the input */
		if (input[read_bytes - 1] == '\n')
			input[read_bytes - 1] = '\0';
		else
			input[read_bytes] = '\0';

		/* Exiting the shell upon 'exit' command */
		if (strcmp(input, "exit") == 0)
			break;

		/* Simulating command execution by echoing the entered command */
		printf("Executing command: %s\n", input);
	}

	return 0;
}

