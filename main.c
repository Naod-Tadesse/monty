#include "monty.h"

/**
 * main - the program main
 * @argc: arg num
 * @argv: the args
 * Return: 0
 */
int main(int argc, char *argv[])
{
	FILE *mfile;
	stack_t *stack = NULL;
	instruction_t co_op[] = {{"push", push_sq}, {"pall", pall_sq},
{"pint", pint_sq}, {"pop", pop_sq}, {"swap", swap_sq}, {"add", add_sq},
{"nop", nop_sq}, {"sub", sub_sq}, {"div", div_sq}, {"mul", mul_sq},
{"mod", mod_sq}, {"pchar", pchar_sq}, {"pstr", pstr_sq}, {NULL, NULL}};
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(1);
	}

	mfile = fopen(argv[1], "r");
	if (!mfile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	handle_op(mfile, &stack, co_op);
	frees(stack);
	fclose(mfile);
	return (0);
}
