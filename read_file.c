#include "monty.h"

/**
 * parse_line - processes lines from files
 * @string: pointer to string
 */

void parse_line(char *string)
{
        const char s[2] = " ";
        char *token;


	token = strtok(string, s);
	while (token != NULL)
	{
		if (strcmp(token, "pall") == 0)
			pall();
		if (strcmp(token, "push") == 0)
			push(5);
/*		printf("Token: %s\n", token);*/
		token = strtok(NULL, s);
	}
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
