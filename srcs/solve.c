#include "push_swap.h"

static void     small_sort(t_stack *stack, int max)
{

}

static void     big_sort(t_stack *stack, int cnt)
{
    int     swap_cnt;

    swap_cnt = 0;
    while (stack->a_head && swap_cnt < stack->pivot->index)
    {
        if (stack->a_head->index < stack->pivot->index)
        {
            push("pb", stack);
            swap_cnt += 1;
        }
        else
            rotater("ra", stack);
    }
    big_sort_swap(stack, 0, stack->pivot->index - 1);

    swap_cnt = cnt;
    while (stack->a_head->index >= stack->pivot->index)
        push("pb", stack);
    big_sort_swap(stack, stack->pivot->index, cnt);
}

void            solve(t_stack *stack, int max)
{
    if (max > 10)
        big_sort(stack, max);
    else
        small_sort(stack, max);
}