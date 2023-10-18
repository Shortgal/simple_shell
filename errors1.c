#include "shell.h"

/**
 * _erratoi - converts a string to an integer
 * @s: the string to be conveted
 * Return: 0 if no numbers in string
 */
int _erratoi(char *s)
{
	int j = 0;
	unsigned long int = 0;

	if (*s == '+')
		s++;  /*TODO: why does this make main return 255? */
	for (j = 0; s[j] != '\0'; j++)
	{
		if (s[j] >= '0' && s[j] <= '9')
		{
			result *= 10;
			result += (s[j] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}
/**
 * print_error - prints an error error message
 * @info: the parameter & return info struct
 * @est: string containing specified error type
 * Return: 0 if no numbers in string, otherwise  -1 on error
 */
