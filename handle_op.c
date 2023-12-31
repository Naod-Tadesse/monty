#include "monty.h"
unsigned int valie = 0;
/**
 * handle_op - this function handles opcode operation
 * @mfile: file pointer
 * @stack: stack pointer
 * @co_op: instruction array
 * Return: if success 1, or 0
 */
int handle_op(FILE *mfile, stack_t **stack, instruction_t *co_op)
{
	char *command = NULL, *first;
	size_t size = 0, i = 0;
	unsigned int line_c = 1;

	valie = 0;
	while (getline(&command, &size, mfile) > 0)
	{
		first = _strtokenizer(command, " \n\t");
		i = 0;
		while (co_op[i].opcode && first)
		{
			if (first && first[0] == '#')
				break;
			if (strcmp(first, co_op[i].opcode) == 0)
			{
				co_op[i].f(stack, line_c);
				if (valie == 4)
				{
					fclose(mfile);
					free(command);
					valie = 0;
					exit(EXIT_FAILURE);
				}
				break;
			}
			i++;
		}
		line_c++;
	}
	if (first)
		if (!co_op[i].opcode)
		{
			line_c = line_c - 1;
			fprintf(stderr, "L%d: unknown instruction %s\n", line_c, first);
			fclose(mfile);
			frees(*stack);
			exit(EXIT_FAILURE);
		}
	free(command);
	return (0);
}
