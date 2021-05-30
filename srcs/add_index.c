#include "push_swap.h"

void    add_index(t_stack *stack, int max)
{
    t_node  *node;
    t_node  *diff;

    node = stack->a_head;
    while (node != NULL)
    {
        diff = stack->a_head;
        while (diff != NULL)
        {
            if (node->nbr > diff->nbr)
                node->index++;
            diff = diff->next;
        }
        if (node->index == (max - (max / 2)))
            stack->pivot = node;
        node = node->next;
    }
}