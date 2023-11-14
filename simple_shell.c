#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_AV 64

int main(int ac, char **av, char **envp) 
{
    char *input = NULL, *token;
    size_t input_size = 0;
    ssize_t input_length;
    pid_t pid;
    int i;

    while (1) {
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
	    {
		    input[input_length - 1] = '\0';
	    }

	    /* Tokenizing input to get command and arguments */
	    ac = 0;
	    token = strtok(input, " ");
	    while (token != NULL && ac < MAX_AV - 1)
	    {
		    av[ac++] = strdup(token);
		    token = strtok(NULL, " ");
	    }
	    av[ac] = NULL;

	    if (ac > 0)
	    {
		    /* Execute the command using fork and exec */
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
	    /* free arguments memory */
	    for (i = 0; i < ac; i++)
		    free(av[i]);
    }

    return 0;
}
