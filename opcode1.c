#include "monty.h"

/**
 * push - pushes a value to the stack
 * @stack: stack of values
 * @line_number: line number of file
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	(void)line_number;
	head = malloc(sizeof(stack_t));
	if (head == NULL)
	{
		printf("Error: malloc failed\n");
		free_list(stack);
		free_vars();
		exit(EXIT_FAILURE);
	}
	head->n = global_vars.value;
	head->prev = NULL;
	if (*stack == NULL)
	{
		head->next = NULL;
		*stack = head;
	}
	else
	{
		head->next = *stack;
		(*stack)->prev = head;
		*stack = head;
	}
/*	printf("PUSH CALLED: %d\n", global_value);*/
/*	printf("line number: %d\n", line_number);*/

}

/**
 * pall - prints all values from the stack
 * @stack: stack of values
 * @line_number: line number of file
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	(void)line_number;
	head = *stack;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
/*	printf("PALL CALLED!\n");*/
/*	printf("line number: %d\n", line_number);*/
}
