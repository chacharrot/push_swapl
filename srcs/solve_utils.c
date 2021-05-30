#include "push_swap.h"

void     big_sort_swap(t_stack *stack, int min, int max)
{
    int     i;

    i = 0;
    while (stack->b_head)
    {
        if (stack->b_head->index == min)
        {
            push("pa", stack);
            rotater("ra", stack);
            min += 1;
        }
        else if (stack->b_head->index == max)
        {
            push("pa", stack);
            max -= 1;
            i++;
        }
        else
            rotater("rb", stack);
    }
    while (i-- > 0)
        rotater("ra", stack);
}