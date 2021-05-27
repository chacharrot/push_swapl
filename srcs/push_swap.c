#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack;
	int	i;
	t_node	*node;

	if (ac < 2 || av[1] == "")
		return (0);

	if (!(stack = create_stack(ac, av)))
		return (0);
	add_index(stack, ac);
	
	// test code
	i = 0;
	node = stack->a_head;
	while (i < ac - 1)
	{
		printf("n : %d, i : %d\n", node->nbr, node->index);
		printf("pivot : %d\n", stack->pivot);
		node = node->next;
		i++;
	}

	return (0);
}
