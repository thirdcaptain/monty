#include "monty.h"

/**
 * is_number - determines if a string is a number
 * @string: string to process
 *
 * Return: 0 if string is a number, 1 if not a number
 */

int is_number(char *string)
{
	int num_digits = 0, i = 0;
	int length = 0;

	length = strlen(string);

	if (string[0] == '-')
		num_digits++;

	while (string[i] != '\0')
	{
		if (isdigit(string[i]) != 0)
			num_digits++;
		i++;
	}

	if (num_digits == length)
		return (0);

	return (1);
}

/**
 * remove_newline - remove newline at end of string
 * @string: string to process
 */

void remove_newline(char *string)
{
	int i = 0;

	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == '\n')
			string[i] = '\0';
	}
}
