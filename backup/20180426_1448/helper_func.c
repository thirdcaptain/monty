#include "monty.h"

/**
 * is_number - determines if a string is a number
 * @string: string to process
 *
 * Return: 0 if string is a number, 1 if not a number
 */

int is_number(char *string)
{
	int converted = 0, num_digits = 0;
	int length = 0;

	length = strlen(string);
	converted = atoi(string);

	if (string[0] == '-')
		num_digits++;

	while (converted != 0)
	{
		converted /= 10;
		num_digits++;
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

/*
int main(void)
{
        char *s1 = "5";
        char *s2 = "-5";
        char *s3 = "pall";
        int value = 0;

        printf("s1: %d\n", atoi(s1));
        value = is_number(s1);
        if (value == 0)
                printf("%s is a number\n", s1);
        else
                printf("%s is not a number\n", s1);

        printf("s2: %d\n", atoi(s2));
        value = is_number(s2);
        if (value == 0)
                printf("%s is a number\n", s2);
        else
                printf("%s is not a number\n", s2);

        printf("s3: %d\n", atoi(s3));
        value = is_number(s3);
        if (value == 0)
                printf("%s is a number\n", s3);
        else
                printf("%s is not a number\n", s3);

        return(0);
}
*/
