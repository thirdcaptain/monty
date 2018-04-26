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

	(void)argv;
/*	if (argc < 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fileptr = fopen(argv[1], "r");
*/	fileptr = fopen("bytecodes/1.m", "r");
	if (fileptr == NULL)
	{
		printf("Error: Can't open file <file>\n");
		exit(EXIT_FAILURE);
	}
	read_file(fileptr);

	fclose(fileptr);

	return (0);
}
