#ifndef MONTY_H
#define MONTY_H

#define TRUE 1
#define FALSE 0
#define DEBUG 1

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;

} stack_t;

/**
 * struct var_t - defines the struct to save the file $ content
 * @file: a pointer to monty file
 * @flag: a flag indicator
 * @args: defines stack args
 * @content: defines the content from command line arguments
 * Description: carries the values of the program
 */

typedef struct var_s
{
    int flag;
    FILE *file;
    char *content;
    char *args;
} var_t;
extern var_t var;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**/
int call_stack(char *content, stack_t **stack, unsigned int counter, FILE *file);

/*basic stack operations */

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char *clean_line(char *content);

void _pint(stack_t **stack, unsigned int line_num);
void _push(stack_t **stack, unsigned int line_num);
void _pop(stack_t **stack, unsigned int line_num);
void _pall(stack_t **stack, unsigned int line_num __attribute__((unused)));
void _swap(stack_t **stack, unsigned int line_num);
void _nop(stack_t **stack, unsigned int line_num);
void _pchar(stack_t **stack, unsigned int line_num);
void _pstr(stack_t **stack, unsigned int line_num);

/*add node at the */
void addnode(stack_t **stack, int n);
/* */
void _tail(stack_t **stack, int n);
void _dequeue(stack_t **stack, unsigned int line_num);
void _stack(stack_t **stack, unsigned int line_num);
void addnode(stack_t **stack, int n);

/*rotates stack */
void _rotbut(stack_t **stack, __attribute__((unused)) unsigned int line_num);
void _rottop(stack_t **stack, unsigned int line_num);

/* stack arithemetic operation*/
void add_top(stack_t **stack, unsigned int line_num);
void _div(stack_t **stack, unsigned int line_num);
void _mul(stack_t **stack, unsigned int line_num);
void _mod(stack_t **stack, unsigned int line_num);
void _sub(stack_t **stack, unsigned int line_num);

void addqueue(stack_t **head, int n);
void f_queue(stack_t **head, unsigned int counter);

/* free the stack */
void free_stack(stack_t *stack);

#endif /* MONTY_H */