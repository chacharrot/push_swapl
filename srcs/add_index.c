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
        if (node->index == (max - ((max / 6) * 5)))
            stack->pivot1 = node;
        // else if (node->index == (max - ((max / 11) * 9)))
        //     stack->pivot2 = node;
        // else if (node->index == (max - ((max / 11) * 8)))
        //     stack->pivot3 = node;
        // else if (node->index == (max - ((max / 11) * 7)))
        //     stack->pivot4 = node;
        // else if (node->index == (max - ((max / 11) * 6)))
        //     stack->pivot5 = node;
        // else if (node->index == (max - ((max / 11) * 5)))
        //     stack->pivot6 = node;
        else if (node->index == (max - ((max / 6) * 4)))
            stack->pivot2 = node;
        else if (node->index == (max - ((max / 6) * 3)))
            stack->pivot3 = node;
        else if (node->index == (max - ((max / 6) * 2)))
            stack->pivot4 = node;
        else if (node->index == (max - (max / 6)))
            stack->pivot5 = node;
        node = node->next;
    }
}