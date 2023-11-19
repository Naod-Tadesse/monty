#include "monty.h"

/**
 * add_sq - adds top two elements
 * @addon: the stack
 * @line_c: the number of lines
 * Return: nothing
 */

void add_sq(stack **addon, unsigned int line_c)
{
	stack_t *first_top;
	stack_t *second_top;

	if (*addon == NULL == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_c);
		frees(*addon);
		valie = 4;
		return;
	}
	else if ((*addon)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_c);
		frees(*addon);
		valie = 4;
		return;
	}
	first_top = *addon;
	second_top = (*addon)->next;
	second_top->n = second_top->n + first_top->n;
	*addon = second_top
	free(first_top);
}
