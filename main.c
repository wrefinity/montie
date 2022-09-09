#include "monty.h"

/*intialize the global variable for the program */
var_t var = {0, NULL, NULL, NULL};

/**
 * main - process function
 *
 * @argc: number of argument
 * @argv: argument vector
 *
 */

int main(int argc, char **argv)
{
    char *line_read = NULL;
    FILE *file;
    char *tokens = NULL;
    int byt_read = 1;
    size_t size;
    stack_t *head = NULL; /* defines the head of the pointer */
    unsigned int counter = 0;

    /* check that the command line argument is exactly two else error message */
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file \n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Fatal Error: can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    var.file = file;

    while (byt_read > 0)
    {
        line_read = NULL;
        byt_read = getline(&line_read, &size, file);
        var.content = line_read;
        counter++;
        if (byt_read > 0)
        {
            call_stack(line_read, &head, counter, file);
        }
        free(line_read);
    }
    free_stack(head);
    fclose(file);

    return (0);
}