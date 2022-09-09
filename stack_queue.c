#include "monty.h"
/**
 * _dequeue - prints the top
 * @stack: stack head
 * @line_num: line_number
 * Return: nothing
 */
void _dequeue(stack_t **stack, unsigned int line_num)
{
    (void)stack;
    (void)line_num;
    var.flag = TRUE;
}

/**
 * _tail - add node to the tail stack
 * @n: new_value
 * @stack: head of the stack
 * Return: nothing
 */
void _tail(stack_t **stack, int n)
{
    stack_t *n_node, *tmp;

    tmp = *stack;
    n_node = malloc(sizeof(stack_t));
    if (n_node == NULL)
    {
        printf("Error\n");
    }
    n_node->n = n;
    n_node->next = NULL;
    if (tmp)
    {
        while (tmp->next)
            tmp = tmp->next;
    }
    if (!tmp)
    {
        *stack = n_node;
        n_node->prev = NULL;
    }
    else
    {
        tmp->next = n_node;
        n_node->prev = tmp;
    }
}

/**
 * _stack - prints the top
 * @stack: stack head
 * @line_num: line_number
 * Return: nothing
 */
void _stack(stack_t **stack, unsigned int line_num)
{
    (void)stack;
    (void)line_num;
    var.flag = FALSE;
}