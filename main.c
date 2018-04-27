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
	stack_t *stack = NULL;

	(void)argv;
	if (argc < 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fileptr = fopen(argv[1], "r");

/*	fileptr = fopen("bytecodes/3.c", "r");*/
	if (fileptr == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read_file(fileptr, &stack);

	fclose(fileptr);

	return (0);
}
