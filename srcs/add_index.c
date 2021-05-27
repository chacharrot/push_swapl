#include "push_swap.h"

void    add_index(t_stack *stack, int ac)
{
    t_node  *node;
    t_node  *diff;
    int     pivot;

    node = stack->a_head;
    pivot = (ac - 1) / 2;

    while (node != NULL)
    {
        diff = stack->a_head;
        while (diff != NULL)
        {
            if (node->nbr > diff->nbr)
                node->index++;
            diff = diff->next;
        }
        if (node->index == pivot)
            stack->pivot = node->nbr;
        node = node->next;
    }
}