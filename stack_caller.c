#include "monty.h"

/**
 * call_stack - executes the opcode
 * @stack: head of the list
 * @counter: line_counter
 * @file: poiner to monty file
 * @content: line content
 * Return: no return
 */
int call_stack(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
    instruction_t inst[] = {
        {"push", _push},
        {"pall", _pall},
        {"pint", _pint},
        {"pop", _pop},
        {"swap", _swap},
        {"add", add_top},
        {"nop", _nop},
        {"sub", _sub},
        {"div", _div},
        {"mul", _mul},
        {"mod", _mod},
        {"pchar", _pchar},
        {"pstr", _pstr},
        {"rotl", _rottop},
        {"rotr", _rotbut},
        {"queue", _tail},
        {"stack", _stack},
        {NULL, NULL}};
        
    unsigned int x = 0;
    char *op_tok;

    op_tok = strtok(content, " \n\t");
    if (op_tok && op_tok[0] == '#')
        return (0);
    var.args = strtok(NULL, " \n\t");
    while (inst[x].opcode && op_tok)
    {
        if (strcmp(op_tok, inst[x].opcode) == 0)
        {
            inst[x].f(stack, counter);
            return (0);
        }
        x++;
    }
    if (op_tok && inst[x].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", counter, op_tok);
        fclose(file);
        free(content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    return (1);
}