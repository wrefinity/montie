#include "monty.h"
/**
 * _pall - prints the stack
 * @stack: stack head
 * @line_num: line_number
 * Return: no return
 */
void _pall(stack_t **stack, unsigned int line_num __attribute__((unused)))
{
    stack_t *tmp;
    tmp = *stack;

    if (tmp == NULL)
        return;
    while (tmp)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}

/**
 * _pop - get the top stack element
 * @stack: stack head
 * @line_num: line_number
 * Return: no return
 */
void _pop(stack_t **stack, unsigned int line_num)
{
    stack_t *tmp;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
        fclose(var.file);
        free(var.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    tmp = *stack;
    *stack = tmp->next;
    free(tmp);
}

/**
 * _push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void _push(stack_t **stack, unsigned int line_num)
{
    int n, j = 0, flag = 0;

    if (var.args)
    {
        if (var.args[0] == '-')
            j++;
        for (; var.args[j] != '\0'; j++)
        {
            if (var.args[j] > 57 || var.args[j] < 48)
                flag = 1;
        }
        if (flag == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_num);
            fclose(var.file);
            free(var.content);
            free_stack(*stack);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_num);
        fclose(var.file);
        free(var.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    n = atoi(var.args);
    if (var.flag == 0)
        addnode(stack, n);
    else
        addqueue(stack, n);
}

/**
 * _pint - prints the top element of the stack
 * @stack: stack head
 * @line_num: line_number
 * Return: no return
*/
void _pint(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}