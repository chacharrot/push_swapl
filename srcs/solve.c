#include "push_swap.h"

static void     small_sort(t_stack *stack, int max)
{

}

static void     big_sort(t_stack *stack, int cnt)
{
    big_sort_split(stack, 0, stack->pivot1->index);
    big_sort_split(stack, stack->pivot1->index, stack->pivot2->index);
    big_sort_split(stack, stack->pivot2->index, stack->pivot3->index);
    big_sort_split(stack, stack->pivot3->index, stack->pivot4->index);
    big_sort_split(stack, stack->pivot4->index, stack->pivot5->index);
    // big_sort_split(stack, stack->pivot5->index, stack->pivot6->index);
    // big_sort_split(stack, stack->pivot6->index, stack->pivot7->index);
    // big_sort_split(stack, stack->pivot7->index, stack->pivot8->index);
    // big_sort_split(stack, stack->pivot8->index, stack->pivot9->index);
    // big_sort_split(stack, stack->pivot9->index, stack->pivot10->index);
    big_sort_split(stack, stack->pivot5->index, cnt);

    big_sort_swap_first(stack, stack->pivot5->index, cnt);
    // big_sort_swap_end(stack, stack->pivot9->index, stack->pivot10->index);
    // big_sort_swap_end(stack, stack->pivot8->index, stack->pivot9->index);
    // big_sort_swap_end(stack, stack->pivot7->index, stack->pivot8->index);
    // big_sort_swap_end(stack, stack->pivot6->index, stack->pivot7->index);
    // big_sort_swap_end(stack, stack->pivot5->index, stack->pivot6->index);
    big_sort_swap_end(stack, stack->pivot4->index, stack->pivot5->index);
    big_sort_swap_end(stack, stack->pivot3->index, stack->pivot4->index);
    big_sort_swap_end(stack, stack->pivot2->index, stack->pivot3->index);
    big_sort_swap_end(stack, stack->pivot1->index, stack->pivot2->index);
    big_sort_swap_end(stack, 0, stack->pivot1->index);
}

void            solve(t_stack *stack, int max)
{
    if (max > 10)
        big_sort(stack, max);
    else
        small_sort(stack, max);
}