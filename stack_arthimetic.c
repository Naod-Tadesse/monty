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

/**
 * pchar_sq - converts int to char in the stack
 * @p: the stack
 * @line_c: the number of lines
 * Return: nothing
 */

void pchar_sq(stack_t **p, unsigned int line_c)
{
	stack_t *ht = *p;
	int ch;

	if (ht == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_c);
		frees(*p);
		valie = 4;
		return;
	}
	else
	{
		ch = ht->n;
	}
	if (!(ch > 0 && ch < 127))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_c);
		frees(*p);
		valie = 4;
		return;
	}
	printf("%c\n", ch);
}

/**
 * pstr_sq - prints string from stack
 * @st: the stack
 * @line_c: the number of lines
 * Return: nothing
 */

void pstr_sq(stack_t **st, unsigned int line_c)
{
	stack_t *t = *st;
	(void)line_c;

	while (t != NULL)
	{
		if (*st < 0 || *st == 0 || *st > 127)
			break;
		printf("%c", t->n);
		t = t->next;
	}
	printf("\n");
}
