#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack;
	int	i;
	t_node	*node;

	if (ac < 2 || av[1] == 0)
		return (0);

	if (!(stack = create_stack(ac, av)))
		return (0);
	add_index(stack, ac - 1);
	solve(stack, ac - 1);

	// test code
	i = 0;
	node = stack->a_head;
	while (node)
	{
		printf("[a] n : %d, i : %d\n", node->nbr, node->index);
		node = node->next;
		i++;
	}
	i = 0;
	node = stack->b_head;
	while (node)
	{
		printf("[b] n : %d, i : %d\n", node->nbr, node->index);
		node = node->next;
		i++;
	}
	printf("count : %d\n", stack->count);

	free_node(stack->a_head);
	free(stack);
	return (0);
}