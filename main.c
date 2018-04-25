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

	if (argc < 2)
	{
		printf("Requires two arguments\n");
		return (-1);
	}
	fileptr = fopen(argv[1], "r");
	if (fileptr == NULL)
		exit(EXIT_FAILURE);

	read_file(fileptr);

	fclose(fileptr);

	return (0);
}
