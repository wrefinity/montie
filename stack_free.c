#include "monty.h"
/**
* free_stack - a func to free stack
* @stack: head of the stack
*/
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	tmp = stack;
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}