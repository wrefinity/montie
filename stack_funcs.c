#include "monty.h"
/**
 * _swap - swaps elements of stack.
 * @stack: define the head of stack
 * @line_num: line_number
 * Return: nothing
*/
void _swap(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;
	int len = 0, swp;

	tmp = *stack;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	swp = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = swp;
}

#include "monty.h"
/**
  *_nop- nothing
  *@stack: stack head
  *@line_num: line_number
  *Return: nothing
 */
void _nop(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
}

/**
 * _pchar - prints the char at the top of the stack
 * @stack: stack head
 * @line_num: line_number
 * Return: no return
*/
void _pchar(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	tmp = *stack;
	if (!tmp)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (tmp->n > 127 || tmp->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", tmp->n);
}

#include "monty.h"
/**
 * _pstr - prints the string starting at the top of the stack,
 * followed by a new
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void _pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;
	(void)line_num;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->n > 127 || tmp->n <= 0)
		{
			break;
		}
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}