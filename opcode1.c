#include "monty.h"

/**
 * push - pushes a value to the stack
 * @stack: stack of values
 * @line_number: line number of file
 */

void push(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	printf("PUSH CALLED: %d\n", global_value);
	printf("line number: %d\n", line_number);
}

/**
 * pall - prints all values from the stack
 * @stack: stack of values
 * @line_number: line number of file
 */

void pall(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	printf("PALL CALLED!\n");
	printf("line number: %d\n", line_number);
}
