#include "push_swap.h"

int			main(int ac, char **av)
{
	t_stack	*stack;

	if (ac < 2 || av[1] == 0)
		return (0);
	if (!(stack = create_stack(ac, av)))
		return (0);
	add_index(stack, ac - 1);
	solve(stack, ac - 1);
	free_node(stack->a_head);
	free(stack);
	return (0);
}
