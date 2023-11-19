#include "monty.h"

/**
 * mod_sq - computes mod of two numbers
 * @modon: the stack
 * @line_c: the number of lines
 * Return: nothing
 */


void mod_sq(stack_t **modon, unsigned int line_c)
{
	stack_t *first_top;
	stack_t *second_top;

	if (*modon == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_c);
		frees(*modon);
		valie = 4;
		return;
	}
	else if ((*modon)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_c);
		frees(*modon);
		valie = 4;
		return;
	}
	else if ((*modon)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_c);
		frees(*modon);
		valie = 4;
		return;
	}
	first_top = *modon;
	second_top = (*modon)->next;
	second_top->n = second_top->n % first_top->n;
	*modon = second_top;
	free(first_top);
}
