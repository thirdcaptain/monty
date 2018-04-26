#include "monty.h"

int is_number(char *string)
{
	int length = 0, digitcount = 0;
	int i = 0;

	length = strlen(string);
	for (i = 0; string[i] != '\0'; i++)
	{
		if(isdigit(string[i]) != 0)
			digitcount++;
	}
	if (digitcount == length)
		return (0);

	return (1);
}

int main(void)
{
	char *s1 = "cow";
	char *s2 = "123";
	char *s3 = "1c3";
	int value = 0;

	value = is_number(s1);
	if (value == 0)
		printf("%s is a number\n", s1);
	else
		printf("%s is not a number\n", s1);
	value = is_number(s2);
	if (value == 0)
		printf("%s is a number\n", s2);
	else
		printf("%s is not a number\n", s2);
	value = is_number(s3);
	if (value == 0)
		printf("%s is a number\n", s3);
	else
		printf("%s is not a number\n", s3);

	return(0);
}
