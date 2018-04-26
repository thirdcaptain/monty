#include "monty.h"

/**
 * is_number - determines if a string is a number
 * @string: string to process
 *
 * Return: 0 if string is a number, 1 otherwise
 */

int is_number(char *string)
{
	int length = 0, digitcount = 0;
	int i = 0;

	length = strlen(string);
	for (i = 0; string[i] != '\0'; i++)
	{
		if (isdigit(string[i]) != 0)
			digitcount++;
	}
	if (digitcount == length)
		return (0);

	return (1);
}
