#include "shell.h"

/**
 * _strlen - returns length of a string
 * @s: string to be inputted
 *
 * Return: length of string
 */

int _strlen(char *s)
{
        int i = 0;

        while (s[i] != '\0')
                i++;

        return (i);
}
