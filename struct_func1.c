#include "shell.h"
/**
 *  _strlen - Calculates the length of string
 * @str: pointer to a strin
 *
 * Return: i int
 */

int _strlen(char *str)
{
	int i = 0;

	while (str[i])
	{
		i++;
	}
	return (i);
}
/**
 * _strcat - concatenate two strings
 *
 * @desti: destination string
 * @sourc: source srting
 * Return: desti
 */
char *_strcat(char *desti, char *sourc)
{
	int i = 0;
	int j = 0;

	while (desti[i] != '\0')
	{
		i++;
	}
	while (sourc[j] != '\0')
	{
		desti[i] = sourc[j];
		i++;
		j++;
	}
	desti[i] = '\0';
	return (desti);
}
/**
  * _strcpy - copy string to another.
  * @desti: destination string
  * @sourc: the string that we have to copy
  *
  * Return: the pointer to desti
  */

char *_strcpy(char *desti, char *sourc)
{
	int i = 0;

	while (*(sourc + i))
	{
		*(desti + i) = *(sourc + i);
		i++;
	}
	*(desti + i) = '\0';

	return (desti);
}
/**
 * _strdup - duplicate string and returns a pointr to newly allocated str.
 * @str: ptr to be duplicated.
 *
 * Return: NULL or str1.
 */

char *_strdup(char *str)
{
	char *str1;
	unsigned int len;

	if (str == 0)
	{
		return (NULL);
	}
	len = _strlen(str) + 1;
	str1 = (char *)malloc(sizeof(char) * len);
	if (str1 == 0)
	{
		return (NULL);
	}
	_memcpy(str1, str, len);
	return (str1);
}
/**
 * _memcpy - funct that copy memory area.
 * @desti: destination memory area.
 * @sourc: source memory ares.
 * @n: number of bytes to be copied.
 *
 * Return: desti.
 */

char *_memcpy(char *desti, char *sourc, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		desti[i] = sourc[i];
	}
	return (desti);
}
