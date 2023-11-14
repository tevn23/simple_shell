#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	ssize_t readline;
	size_t buffersize = 0;
	char *buffer = NULL;
	char *buffer_copy;
	char * token;
	char * del = " \n";
	int count = 0;
	int i;
	char *token2;
	int returnexec;
	int j;

	while (1)
	{
	printf("$ ");
	readline = getline(&buffer, &buffersize, stdin);
	//printf("%s", buffer);

	if (readline == -1)
	{
		perror (" end of line ");
		exit(1);
	}

	buffer_copy = malloc(sizeof(char) * readline);
	if (buffer_copy == NULL)
	{
		printf("malloc failed ");
		exit(1);
	}
	
	strcpy(buffer_copy, buffer);
	token = strtok(buffer_copy, del);
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, del);
		count++;
	}
	argv = malloc(sizeof(char *) * count);
	
	token2 = strtok(buffer, del);

	for(i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token2) +1);
		strcpy(argv[i], token2);
		token2 = strtok(NULL, del);
	}
	argv[i] = NULL;

	returnexec = execve(argv[0], argv, NULL);
	if (returnexec == -1)
	{
		perror("execve failed ");
		exit(1);
	} 

	for(j = 0; j < i; j++)
	{
		free (argv[j]);
	}
	
	free(argv);
	} 
	free(buffer_copy);
	free(buffer);
	return (0);
	}