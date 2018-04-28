#include "monty.h"

/**
 * pint - prints the value at the top of the stack, followed by a new line
 * @stack: stack of values
 * @line_number: line number of file
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	head = *stack;
	if (head == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: stack of values
 * @line_number: line number of file
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	stack_t *temp;
	int count = 0;

	head = *stack;
	if (head == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	head = *stack;
	if (count == 1)
	{
		free(head);
		*stack = NULL;
		return;
	}
	temp = head;
	head = head->next;
	head->prev = NULL;
	(*stack) = head;
	free(temp);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: stack of values
 * @line_number: line number of file
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	stack_t *temp;
	int count = 0;
	int temp_num = 0;

	head = *stack;
	if (head == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	if (count < 2)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	head = *stack;
	temp = head->next;
	temp_num = head->n;
	head->n = temp->n;
	temp->n = temp_num;
}

/**
 * add - adds the top two elements of the stack
 * @stack: stack of values
 * @line_number: line number of file
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	stack_t *temp;
	int count = 0;
	int temp_num = 0;

	head = *stack;
	if (head == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	if (count < 2)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	head = *stack;
	temp = head->next;
	temp_num = (head->n) + (temp->n);
	pop(stack, line_number);
	(*stack)->n = temp_num;
}

/**
 * nop - pushes a value to the stack
 * @stack: stack of values
 * @line_number: line number of file
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	return;
}
