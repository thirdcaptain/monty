#include "monty.h"

int is_number(char *string)
{
	int converted = 0, num_digits = 0;
	unsigned int length = 0;

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

int main(void)
{
	char *s1 = "q14";
	char *s2 = "-123ddc";
	char *s3 = "123999";
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
