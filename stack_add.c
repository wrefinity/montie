#include "monty.h"

/**
 * add_top - adds the top two elements of the stack.
 * @stack: defines the head of the stack
 * @line_num: line_number
 * Return: nothing
 */
void add_top(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;
	int len = 0, add;

	tmp = *stack;
	/* get the length of the stack*/
	while (tmp != NULL)
	{
		tmp = tmp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: stack capacity doesnt permit addition to stack \n", line_num);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	add = tmp->n + tmp->next->n;
	tmp->next->n = add;
	/*neglect top node tmp->n, point*/
	*stack = tmp->next;
	free(tmp);
}

/**
 * addnode - add node to the head of stack
 * @stack: head of the stack
 * @n: new_value
 * Return: nothing
 */
void addnode(stack_t **stack, int n)
{
	stack_t *n_node;
	stack_t *tmp;

	tmp = *stack;
	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
	{
		printf("Error: new node is empty \n");
		exit(FALSE);
	}

	/* assign prev pointer which is null to n_node*/
	if (tmp)
		tmp->prev = n_node;
	n_node->n = n;
	n_node->next = *stack;
	n_node->prev = NULL;
	*stack = n_node;
}