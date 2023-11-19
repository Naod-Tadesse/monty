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
		fprintf(stderr, "L%d: usage: push integer\n", line_c);
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
		exit(EXIT_FAILURE);
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

/**
 * pint_sq - prints the top element
 * @tack: the stack
 * @line_c: line num
 * Return: nothing
 */

void pint_sq(stack_t **tack, unsigned int line_c)
{
	if (*tack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_c);
		frees(*tack);
		valie = 4;
		return;
	}
	printf("%d\n", (*tack)->n);
}

/**
 * pop_sq - removes an element from the top
 * @tack: the stack
 * @line_c: line num
 * Return: nothing
 */

void pop_sq(stack_t **tack, unsigned int line_c)
{
	stack_t *l;

	if (*tack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_c);
		frees(*tack);
		valie = 4;
		return;
	}
	l = *tack;
	*tack = (*tack)->next;
	free(l);
}

/**
 * swap_sq - swaps 2 elements in stack
 * @tak: the stack
 * @line_c: the number of lines
 * Return: nothing
 */

void swap_sq(stack_t **tak, unsigned int line_c)
{
	stack_t *top;
	stack_t *bot;

	if (*tak == NULL || (*tak)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",line_c);
		frees(*tak);
		valie = 4;
		return;
	}
	top = *tak;
	bot = top->next;
	top->next = bot->next;
	bot->next = top;
	*tak = bot;
}
