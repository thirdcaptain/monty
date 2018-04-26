#include "monty.h"

/**
 * push - pushes a value to the stack
 */

void push(void)
{
	printf("PUSH CALLED: %d\n", global_value);
	printf("line number: %d\n", line_number);
}

/**
 * pall - prints all values from the stack
 */

void pall(void)
{
	printf("PALL CALLED!\n");
	printf("line number: %d\n", line_number);
}
