#include "monty.h"

/**
 * add_sq - adds top two elements
 * @addon: the stack
 * @line_c: the number of lines
 * Return: nothing
 */

void add_sq(stack_t **addon, unsigned int line_c)
{
	stack_t *first_top;
	stack_t *second_top;

	if (*addon == NULL)
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
	*addon = second_top;
	free(first_top);
}
/**
 * nop_sq - does nothing
 * @tak: the stack
 * @line_c: the number of lines
 * Return: nothing
 */

void nop_sq(stack_t **tak, unsigned int line_c)
{
	(void)tak;
	(void)line_c;
}

/**
 * sub_sq - subtracts top two elements
 * @subon: the stack
 * @line_c: the number of lines
 * Return: nothing
 */

void sub_sq(stack_t **subon, unsigned int line_c)
{
	stack_t *first_top;
	stack_t *second_top;

	if (*subon == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_c);
		frees(*subon);
		valie = 4;
		return;
	}
	else if ((*subon)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_c);
		frees(*subon);
		valie = 4;
		return;
	}
	first_top = *subon;
	second_top = (*subon)->next;
	second_top->n = second_top->n - first_top->n;
	*subon = second_top;
	free(first_top);
}

/**
 * div_sq - devides top two elements
 * @divon: the stack
 * @line_c: the number of lines
 * Return: nothing
 */

void div_sq(stack_t **divon, unsigned int line_c)
{
	stack_t *first_top;
	stack_t *second_top;

	if (*divon == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_c);
		frees(*divon);
		valie = 4;
		return;
	}
	else if ((*divon)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_c);
		frees(*divon);
		valie = 4;
		return;
	}
	else if ((*divon)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_c);
		frees(*divon);
		valie = 4;
		return;
	}
	first_top = *divon;
	second_top = (*divon)->next;
	second_top->n = second_top->n - first_top->n;
	*divon = second_top;
	free(first_top);
}
