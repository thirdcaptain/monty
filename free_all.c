#include "monty.h"

/**
 * free_list - frees the linked list
 * @stack: linked list
 */

void free_list(stack_t **stack)
{
	stack_t *temp;

	if (stack == NULL)
		return;

	while ((*stack) != NULL)
	{
		temp = (*stack)->next;
		if (*stack)
			free(*stack);
		*stack = temp;
	}
}

/**
 * free_vars - frees malloced variables
 */

void free_vars(void)
{
	if (global_vars.line)
		free(global_vars.line);
	if (global_vars.array)
		free(global_vars.array);
	if (global_vars.file)
		fclose(global_vars.file);
}
