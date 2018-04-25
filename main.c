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

	if (argc < 2)
	{
		printf("Requires two arguments\n");
		return (1);
	}

	fileptr = fopen(argv[1], "r");
	if (fileptr == NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, fileptr)) != -1) {
		printf("Retrieved line of length %zu :\n", read);
		printf("%s", line);
	}

	fclose(fileptr);
	if (line)
		free(line);

	return (0);
}
