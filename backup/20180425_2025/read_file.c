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
/*	const char s[2] = " ";
	char *token;
	int value = 0;

	token = strtok(string, s);
	while (token != NULL)
	{
		if (strcmp(token, "pall") == 0)
			pall();
		if (strcmp(token, "push") == 0)
			push(value);
		printf("Token: %s\n", token);
		token = strtok(NULL, s);
	}
*/
	char **array_strings;
	int i = 0;

	array_strings = ret_array(string);
	for (i = 0; array_strings[i] != NULL; i++)
	{
		printf("[%d]: %s\n", i, array_strings[i]);
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
