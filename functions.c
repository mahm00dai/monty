#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The current line number in the bytecode file.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \n");  // Get the next token after the opcode
	int n;

	if (arg == NULL || !is_number(arg))  // Check for valid argument
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(arg);  // Convert the argument to an integer

	// Create a new node
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)  // Check for memory allocation failure
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;  // Point to the current top of the stack

	if (*stack != NULL)  // Update the previous pointer of the current top
	{
		(*stack)->prev = new_node;
	}
	
	*stack = new_node;  // Update the stack head to the new node
}

/**
 * pall - Prints all the values on the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The current line number in the bytecode file (not used).
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current = *stack;  // Start from the top of the stack

	while (current)  // Traverse the stack
	{
		printf("%d\n", current->n);
		current = current->next;  // Move to the next node
	}
}

/**
 * is_number - Checks if a string represents a valid integer.
 * @str: The string to check.
 * Return: 1 if valid integer, 0 otherwise.
 */
int is_number(const char *str)
{
	if (*str == '-' || *str == '+')  // Allow optional sign
		str++;

	while (*str)  // Check each character
	{
		if (!isdigit(*str))  // Not a digit
			return 0;
		str++;
	}
	return 1;  // Valid integer
}

