#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - global variables
 * @value: value from string
 * @line: line read from getline
 * @array: array of strings from strtok
 * @file: file descriptor
 */
typedef struct global_s
{
	int value;
	char *line;
	char *array[2];
	FILE *file;
} global_t;

extern global_t global_vars;
global_t global_vars;


int token_count(char *str);
void ret_array(char *string, stack_t **stack);
void read_file(FILE *file, stack_t **stack);
void parse_line(char *string, unsigned int line_number, stack_t **stack);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

int is_number(char *string);
void remove_newline(char *string);

void free_list(stack_t **stack);
void free_vars(void);

#endif
