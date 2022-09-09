#include "monty.h"
/**
  *_rotbut- rotates the stack to the bottom
  *@stack: stack head
  *@line_num: line_number
  *Return: nothing
 */
void _rotbut(stack_t **stack, __attribute__((unused)) unsigned int line_num)
{
	stack_t *cpy;

	cpy = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	while (cpy->next)
	{
		cpy = cpy->next;
	}
	cpy->next = *stack;
	cpy->prev->next = NULL;
	cpy->prev = NULL;
	(*stack)->prev = cpy;
	(*stack) = cpy;
}


/**
  *_rottop- rotates the stack to the top
  *@stack: stack head
  *@line_num: line_number
  *Return: no return
 */
void _rottop(stack_t **stack,  __attribute__((unused)) unsigned int line_num)
{
	stack_t *tmp = *stack, *ahead;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	ahead = (*stack)->next;
	ahead->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = tmp;
	(*stack) = ahead;
}