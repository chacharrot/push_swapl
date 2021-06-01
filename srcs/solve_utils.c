#include "push_swap.h"

void        big_sort_split(t_stack *stack, int min, int max)
{
    t_node  *tmp;
    int     i;

    i = 0;
    while (tmp && i < (max - min))
    {
        tmp = stack->a_head;
        if (tmp->index < max)
        {
            push("pb", stack);
            i++;
        }
        else
            rotater("ra", stack);
    }
}

void        big_sort_swap_first(t_stack *stack, int min, int max)
{
    int     pivot_min;
    int     pivot_max;
    int     i;
    int     cnt;

    pivot_min = (min + max) / 2;
    pivot_max = ((min + max) / 2) + 1;

    i = 0;
    cnt = 0;
    while (i < (max - min))
    {
        if (stack->b_head->index < min)
        {
            while (0 < cnt)
            {
                rev_rotater("rrb", stack);
                if (stack->b_head->index == pivot_min)
                {
                    push("pa", stack);
                    i++;
                    pivot_min -= 1;
                }
                else if (stack->b_head->index == pivot_max)
                {
                    push("pa", stack);
                    rotater("ra", stack);
                    i++;
                    pivot_max += 1;
                }
                cnt--;
            }
        }
        else if (stack->b_head->index == pivot_min)
        {
            push("pa", stack);
            i++;
            pivot_min -= 1;
        }
        else if (stack->b_head->index == pivot_max)
        {
            push("pa", stack);
            rotater("ra", stack);
            i++;
            pivot_max += 1;
        }
        else
        {
            rotater("rb", stack);
            cnt++;
        }
    }
}

void        big_sort_swap_end(t_stack *stack, int min, int max)
{
    int     i;
    int     cnt;
    int     while_end;
    int     min_check;

    i = 0;
    cnt = 0;
    min_check = 0;
    while_end = max - min;
    max -= 1;
    while (i < while_end)
    {
        if (stack->b_head->index < min)
        {
            while (0 < cnt)
            {
                rev_rotater("rrb", stack);
                if (stack->b_head->index == min)
                {
                    if (stack->a_tail->index == stack->b_head->index + 1)
                    {
                        rev_rotater("rra", stack);
                        push("pa", stack);
                        rotater("ra", stack);
                        rotater("ra", stack);
                        min += 2;
                    }
                    else
                    {
                        push("pa", stack);
                        rotater("ra", stack);
                        min += 1;
                    }
                    i++;
                    min_check++;
                }
                else if (stack->b_head->index == max)
                {
                    if (stack->a_head->index == max - 1)
                    {
                        push("pa", stack);
                        swapper("sa", stack);
                        max -= 2;
                    }
                    else
                    {
                        push("pa", stack);
                        max -= 1;
                    }
                    i++;
                }
                cnt--;
            }
        }
        else if (stack->b_head->index == min)
        {
            if (stack->a_tail->index == stack->b_head->index + 1)
            {
                rev_rotater("rra", stack);
                push("pa", stack);
                rotater("ra", stack);
                rotater("ra", stack);
                min += 2;
            }
            else
            {
                push("pa", stack);
                rotater("ra", stack);
                min += 1;
            }
            i++;
            min_check++;
        }
        else if (stack->b_head->index == min + 1)
        {
            push("pa", stack);
            rotater("ra", stack);
            i++;
            min_check++;
        }
        else if (stack->b_head->index == max)
        {
            if (stack->a_head->index == max - 1)
            {
                push("pa", stack);
                swapper("sa", stack);
                max -= 2;
            }
            else
            {
                push("pa", stack);
                max -= 1;
            }
            i++;
        }
        else if (stack->b_head->index == max - 1)
        {
            push("pa", stack);
            i++;
        }
        else
        {
            rotater("rb", stack);
            cnt++;
        }
    }
    while (min_check-- > 0)
        rev_rotater("rra", stack);
}
