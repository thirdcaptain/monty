#include "monty.h"

/**
 * token_count - count number of tokens
 * @str: string to tokenize
 *
 * Return: Number of tokens
 */

int global_value = 0;

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
		return (NULL);
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
 */

void parse_line(char *string)
{
	char **array_strings;
	int i = 0, j = 0;
	instruction_t instruct[] = {
		{"pall", pall},
		{"push", push},
		{NULL, NULL},
	};

	array_strings = ret_array(string);
	for (i = 0; array_strings[i] != NULL; i++)
	{
		printf("[%d]: %s\n", i, array_strings[i]);

		for (j = 0; instruct[j].opcode != NULL; j++)
		{
			if (strcmp(instruct[j].opcode, array_strings[i]) == 0)
			{
				global_value = atoi(array_strings[i + 1]);
				printf("OPCODE:%s\n", instruct[j].opcode);
				printf("global: %d\n", global_value);
			}
		}
/*		if (strcmp(array_strings[i], "pall") == 0)
			pall();
*/
	}
	if (array_strings)
		free(array_strings);

}

/**
 * read_file - reads lines from files
 * @file: pointer to file
 */

void read_file(FILE *file)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while ((read = getline(&line, &len, file)) != -1)
	{
/*              printf("Retrieved line of length %zu :\n", read);*/
		printf("string: %s", line);

		parse_line(line);
	}
	if (line)
		free(line);
}
