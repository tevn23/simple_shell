#include "main.h"

/**
*main- this function will be reposible for calling most of my __fortify_function
*@argc: This is argument count contain the numbers of argument passed
*@argv: This contain array of strings of command to be passed to execve __fortify_functio
*/
int main(int argc, char **argv)
{
    char *buffer = NULL;
    size_t buffersize = 0;
    ssize_t readline;
    pid_t childpid;
    char **array;
    int status, i;
    char promt[] = "vshell$ ";
    char *token;
    
    (void)argc;
    (void)argv;

    while(1)
    {
        write(STDOUT_FILENO, promt, strlen(promt));

        readline = getline(&buffer, &buffersize,stdin);
        if(readline == -1)
        {
            perror("getlne funtion failed ");
            exit(1);
        }
        array = malloc(sizeof(char*) * 1024);
        if (array == NULL)
        {
            perror("malloc faileda");
            exit(1);
        }
        i = 0;
        token = strtok(buffer, " \n");
        while(token != NULL)
        {
            array[i] = token;
            token = strtok(NULL, " \n");
            i++;
        }
        array[i] = NULL;
        //printf("%s", buffer);

        childpid = fork();
        if(childpid == -1)
        {
            perror("fail to creat a porcess");
            exit(1);
        }
        if(childpid == 0)
        {
            if (execve(array[0], array, NULL) == -1)
            {
                perror("could not execute");
                exit(7);
            }
            printf(" The child proces was created sucessfully\n ");
        }
        else
        {
            wait(&status);
        }
    }
    free(buffer);
    return 0;
}