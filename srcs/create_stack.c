#include "push_swap.h"

static int	check_arg(char *av)
{
	int	i;

	i = 0;
	if ('-' == av[i] || '+' == av[i])
		i++;
	while (av[i])
	{
		
		if ('0' > av[i] || av[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int		check_int_range(long long n)
{
	if (-2147483648 <= n && n <= 2147483647)
		return (1);
	return (0);
}

t_node		*create_node(char *av, t_node *now_node)
{
	t_node		*tmp;
	long long	num;
	
	if (!(check_arg(av)))
		return (0);
	num = ft_atol(av);
	if (!(check_int_range(num)))
		return (0);
	if(!(tmp = malloc(sizeof(t_node))))
		return (0);
	if (tmp)
	{
		tmp->nbr = num;
		tmp->prev = now_node;
		tmp->next = NULL;
		tmp->index = 0;
	}
	if (now_node != NULL)
		now_node->next = tmp;
	return (tmp);
}

int			check_double(t_node *node, int ac)
{
	t_node	*diff;

	while (node != NULL)
	{
		diff = node->next;
		while (diff != NULL)
		{
			if (node->nbr == diff->nbr)
				return (0);
			diff = diff->next;
		}
		node = node->next;
	}
	return (1);
}

t_stack		*create_stack(int ac, char **av)
{
	t_stack	*stack;
	t_node	*now_node;
	int	i;

	if(!(stack = malloc(sizeof(t_stack))))
		return (0);
	i = 1;
	now_node = NULL;
	while(i < ac)
	{
		if (!(now_node = create_node(av[i], now_node)))
		{
			free_node(stack->a_head);
			write(2, "Error\n", 6);
			exit(1);
		}
		if (i == 1)
			stack->a_head = now_node;
		i++;
		if (i == ac)
			stack->a_tail = now_node;
	}
	if (!(check_double(stack->a_head, ac)))
	{
		free_node(stack->a_head);
		write(2, "Error\n", 6);
		exit(1);
	}
	stack->b_head = NULL;
	stack->b_tail = NULL;
	stack->pivot = 0;
	stack->count = 0;
	return (stack);
}
