#include "monty.h"

int global_value = 0;

/**
 * token_count - count number of tokens
 * @str: string to tokenize
 *
 * Return: Number of tokens
 */

int token_count(char *str)
{
	int count = 0, i = 0;
	char *dup;

	dup = strdup(str);
	if (dup[i] == '\0')
		return (1);
	while (dup[i] != '\0')
	{
		while (dup[i] == ' ')
		{
			i++;
		}
		if (dup[i] != '\0')
			count++;
		while (dup[i] != ' ' && dup[i] != '\0')
		{
			i++;
		}
	}
	free(dup);
	return (count);
}

/**
 * ret_array - for each word of a string received from getline
 * @string: breaks string into tokens
 *
 * Return: pointer to pointer of arrays of strings
 */

char **ret_array(char *string)
{
	int i = 0;
	int num_token = 0;
	char **array;
	char *token;

	num_token = token_count(string);
	array = malloc((sizeof(char *) * (num_token + 1)));
	if (array == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(string, " ");
	while (token != NULL)
	{
		array[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	array[i] = NULL;
	return (array);
}

/**
 * parse_line - processes lines from files
 * @string: pointer to string
 * @line_number: line number in file
 */

void parse_line(char *string, unsigned int line_number, stack_t **stack)
{
	char **array_strings;
	int i = 0;
	instruction_t instruct[] = {
		{"pall", pall},
		{"push", push},
		{NULL, NULL},
	};

	array_strings = ret_array(string);
	for (i = 0; instruct[i].opcode != NULL; i++)
	{
		if (array_strings[0])
			remove_newline(array_strings[0]);
		if (array_strings[1])
			remove_newline(array_strings[1]);
		printf("array[0]: %s\n", array_strings[0]);
		if (strcmp(instruct[i].opcode, array_strings[0]) == 0)
		{
			if (array_strings[1])
			{
				if (is_number(array_strings[1]) != 0)
				{
					printf("L%d: usage: push integer\n",
					       line_number);
					if (array_strings)
						free(array_strings);
					exit(EXIT_FAILURE);
				}
				global_value = atoi(array_strings[1]);
				instruct[i].f(stack, line_number);
				break;
			}
			else if (array_strings[1] == NULL)
			{
				if (strcmp(instruct[i].opcode, "push") == 0)
				{
					printf("L%d: usage: push integer\n",
					       line_number);
					if (array_strings)
						free(array_strings);
					exit(EXIT_FAILURE);
				}
				instruct[i].f(stack, line_number);
				break;
			}
		}
		printf("global %d\n", global_value);
	}
	if (instruct[i].opcode == NULL && strcmp(array_strings[0], "") != 0)
	{
		printf("L%d: unknown instruction <opcode>\n", line_number);
		if (array_strings)
			free(array_strings);
		exit(EXIT_FAILURE);
	}
	if (array_strings)
		free(array_strings);
}

/**
 * read_file - reads lines from files
 * @file: pointer to file
 */

void read_file(FILE *file, stack_t **stack)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
/*              printf("Retrieved line of length %zu :\n", read);*/
		printf("string: %s", line);
/*		printf("line number: %d\n", line_number);*/
		parse_line(line, line_number, stack);
	}
	if (line)
		free(line);
}
