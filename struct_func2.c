#include "shell.h"


/**
 * _strncpy - function that copies a string
 *
 * @dest: destinat str
 * @src: source srting
 * @n: int that specify the max num of char to copy
 *
 * Return: dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}


/**
 *  _puts - print string to standard output
 * @str: ptr to str.
 * Return: Always 0.
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}


/**
 * _putchar - writes char c to standard output
 * @c: The char to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _strcmp - function that compares two strings.
 *
 * @s1: pointer of the 1st string to be compared.
 * @s2: pointer of the 2nd string to be compared.
 *
 * Return: integer
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}


/**
 * _strncmp - compares first n bytes of s1 and s2
 * @s1: string 1
 * @s2: string 2
 * @n: num of bytes to compare
 * Return: int
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;

	while (s1[i] && (i < n))
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}

	return (0);
}
