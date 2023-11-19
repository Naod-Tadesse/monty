#include "monty.h"

/**
 * handle_op - this function handles opcode operation
 * @mfile: file pointer
 * @stack: stack pointer
 * Return: if success 1, or 0
 */

int handle_op(FILE *mfile, stack_t **stack)
{
	char *del = " \n\t", *command = NULL;
	size_t size = 0;
	int  i = 0;
	unsigned int line_c = 1;
	char *first;
	instruction_t co_op[] = {{"push", push_sq}, {"pall", pall_sq}, {NULL, NULL}};

	while (getline(&command, &size, mfile) != -1)
	{
		first = _strtokenizer(command, del);
		i = 0;
		while (co_op[i].opcode && first)
		{
			if (_strcmp(command, co_op[i].opcode) == 0)
			{
				co_op[i].f(stack, line_c);
				break;
			}
			i++;
		}
		line_c++;
	}
	free(command);
	if (first)
	{
		if (!co_op[i].opcode)
		{
			line_c = line_c - 1;
			fprintf(stderr, "L%d: unknown instruction %s\n", line_c, first);
			free(command);
			fclose(mfile);
			frees(*stack);
			exit(1);
		}
	}
	return (0);
}
