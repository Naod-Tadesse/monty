#include "monty.h"
/**
 * push_sq - this function pushes stack into an item
 * @stack: the stack
 * @line_c: the line number for monty file
 * Return: nothing
 */
void push_sq(stack_t **stack, unsigned int line_c)
{
	char *second;
	int l;
	stack_t *append;

	second = _strtokenizer(NULL, " \n\t");
	if (!second || !_isdi(second))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_c);
		frees(*stack);
		valie = 4;
		return;
	}
	l = atoi(second);
	append = malloc(sizeof(stack_t));
	if (!append)
	{
		fprintf(stderr, "Error: malloc failed\n");
		frees(*stack);
		exit(1);
	}
	append->n = l;
	append->prev = NULL;
	append->next = *stack;
	if (*stack)
	{
		(*stack)->prev = append;
	}
	*stack = append;
}
/**
 * pall_sq - prints all items in stack
 * @tack: the stack
 * @line_c: line number but useless in this function
 * Return: nothing
 *
 */
void pall_sq(stack_t **tack, unsigned int line_c)
{
	stack_t *print;
	(void)line_c;

	print = *tack;
	while (print != NULL)
	{
		printf("%d\n", print->n);
		print = print->next;
	}
}
