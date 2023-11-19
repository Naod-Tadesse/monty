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
	handle_op(mfile, &stack);
	frees(stack);
	fclose(mfile);
	return (0);
}
