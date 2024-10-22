#include "monty.h"

void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	for (int i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

