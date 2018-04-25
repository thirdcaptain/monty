#include "monty.h"

/**
 * main - monty bytecode interpreter
 * @argc: argument count
 * @argv: argument variables
 *
 * Return: 0 on success
 */

int main(int __attribute__((unused))argc, char *argv[])
{
	FILE *fileptr;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	const char s[2] = " ";
	char *token;

	if (argc < 2)
	{
		printf("Requires two arguments\n");
		return (1);
	}

	fileptr = fopen(argv[1], "r");
	if (fileptr == NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, fileptr)) != -1)
	{
/*		printf("Retrieved line of length %zu :\n", read);*/
		printf("string: %s", line);

		token = strtok(line, s);
		while (token != NULL)
		{
			printf("Token: %s\n", token);
			token = strtok(NULL, s);
		}
	}

	fclose(fileptr);
	if (line)
		free(line);

	return (0);
}
