#include "monty.h"

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
 * @stack: pointer to linked list
 *
 * Return: pointer to pointer of arrays of strings
 */

void ret_array(char *string, stack_t **stack)
{
	int i = 0;
/*	int num_token = 0;*/
	char *token;

	(void)stack;
/*
 *	num_token = token_count(string);
 *	global_vars.array = malloc((sizeof(char *) * (num_token + 1)));
 *	if (global_vars.array == NULL)
 *	{
 *		printf("Error: malloc failed\n");
 *		free_list(stack);
 *		free_vars();
 *		exit(EXIT_FAILURE);
 *	}
*/	token = strtok(string, " ");
	while (i < 2)
	{
		global_vars.array[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	global_vars.array[i] = NULL;
/*	return (global_vars.array);*/
}

/**
 * parse_line - processes lines from files
 * @string: pointer to string
 * @line_number: line number in file
 * @stack: linked list
 */

void parse_line(char *string, unsigned int line_number, stack_t **stack)
{
	int i = 0;
	instruction_t instruct[] = {
		{"pall", pall},
		{"push", push},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL},
	};

/*	global_vars.array = ret_array(string, stack);*/
	ret_array(string, stack);
	for (i = 0; instruct[i].opcode != NULL; i++)
	{
		if (global_vars.array[0])
			remove_newline(global_vars.array[0]);
		if (global_vars.array[1])
			remove_newline(global_vars.array[1]);
		if (strcmp(instruct[i].opcode, global_vars.array[0]) == 0)
		{
			if (global_vars.array[1])
			{
				if ((is_number(global_vars.array[1]) != 0 ||
				     strcmp(global_vars.array[1], "") == 0) &&
				    strcmp(global_vars.array[0], "push") == 0)
				{
					printf("L%d: usage: push integer\n",
					       line_number);
					free_list(stack);
					free_vars();
					exit(EXIT_FAILURE);
				}
				global_vars.value = atoi(global_vars.array[1]);
				instruct[i].f(stack, line_number);
				break;
			}
			else if (global_vars.array[1] == NULL)
			{
				if (strcmp(instruct[i].opcode, "push") == 0)
				{
					printf("L%d: usage: push integer\n",
					       line_number);
					free_list(stack);
					free_vars();
					exit(EXIT_FAILURE);
				}
				instruct[i].f(stack, line_number);
				break;
			}
		}
	}
	if (instruct[i].opcode == NULL && strcmp(global_vars.array[0], "") != 0)
	{
		printf("L%d: unknown instruction %s\n", line_number, global_vars.array[0]);
		free_list(stack);
		free_vars();
		exit(EXIT_FAILURE);
	}
/*
 *	if (global_vars.array)
 *		free(global_vars.array);
*/
}

/**
 * read_file - reads lines from files
 * @file: pointer to file
 * @stack: linked list
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
/*		printf("string: %s", line);*/
/*		printf("line number: %d\n", line_number);*/
		global_vars.line = line;
		parse_line(global_vars.line, line_number, stack);
	}
	if (line)
		free(line);
	free_list(stack);
}
