#include "monty.h"
/**
 * _div - divides the top two elements of the stack.
 * @stack: stack head
 * @line_num: line_number
 * Return: nothing
*/
void _div(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;
	int len = 0, div;

	tmp = *stack;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	div = tmp->next->n / tmp->n;
	tmp->next->n = div;
	*stack = tmp->next;
	free(tmp);
}

/**
 * _mod - get the mod from the top elements
 * @stack: stack head
 * @line_num: line_number
 * Return: nothing
*/
void _mod(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;
	int len = 0, mod;

	tmp = *stack;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	mod = tmp->next->n % tmp->n;
	tmp->next->n = mod;
	*stack = tmp->next;
	free(tmp);
}


/**
 * _mul - multiply the top two elements of the stack.
 * @stack: stack head
 * @line_num: line_number
 * Return: nothing
*/
void _mul(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;
	int len = 0, mul;

	tmp = *stack;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	mul = tmp->next->n * tmp->n;
	tmp->next->n = mul;
	*stack = tmp->next;
	free(tmp);
}


/**
  *_sub- substract top two elements
  * @stack: stack head
  * @line_num: line_number
  * Return: nothing
  */
void _sub(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;
	int sub, len;

	tmp = *stack;
	for (len = 0; tmp != NULL; len++)
		tmp = tmp->next;
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	sub = tmp->next->n - tmp->n;
	tmp->next->n = sub;
	*stack = tmp->next;
	free(tmp);
}