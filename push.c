// push.c

#include "monty.h"
#include <stdlib.h>

void push(stack_t **stack, unsigned int line_number, char *arg)
{
    int value;

    if (!arg || (!isdigit(arg[0]) && (arg[0] != '-' && !isdigit(arg[1]))))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(arg);

    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
}

// pall.c

#include "monty.h"
#include <stdio.h>

void pall(stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    stack_t *current = *stack;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

