#ifndef HEADMONTY
#define HEADMONTY
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

extern unsigned int valie;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
void push_sq(stack_t **stack, unsigned int line_c);
void frees(stack_t *head);
int handle_op(FILE *mfile, stack_t **stack, instruction_t *co_op);
int _strcmp(char *string1, char *string2);
char *_strtokenizer(char *str, const char *delimiters);
int _isdi(char *str);
void pall_sq(stack_t **tack, unsigned int line_c);
void pint_sq(stack_t **tack, unsigned int line_c);
void pop_sq(stack_t **tack, unsigned int line_c);
void swap_sq(stack_t **tak, unsigned int line_c);
void add_sq(stack_t **addon, unsigned int line_c);
void nop_sq(stack_t **tak, unsigned int line_c);
void sub_sq(stack_t **subon, unsigned int line_c);
#endif
