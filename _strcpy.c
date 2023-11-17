#include "shell.h"

int _strlen(char *src);

/**
 * _strcpy - copies the string pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed by dest
 * @dest: pointer to buffer
 * @src: string to be copied
 *
 * Return: pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int j;

	for (j = 0; j < _strlen(src) + 1; j++)
	{
		dest[j] = src[j];
	}
	return (dest);
}
