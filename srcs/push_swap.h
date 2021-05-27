#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include "../libft/libft.h"

typedef struct		s_node
{
	int		nbr;
	struct s_node	*next;
	struct s_node	*prev;
	int		index;
}			t_node;

typedef struct		s_stack
{
	t_node		*a_head;
	t_node		*a_tail;
	t_node		*b_head;
	t_node		*b_tail;
	int			pivot;
}			t_stack;

long long	ft_atol(const char *nptr);
t_stack		*create_stack(int ac, char **av);
void    add_index(t_stack *stack, int ac);

void	push(t_node **from_head, t_node **to_head, t_node **to_tail)
void	swap(t_node **head)
void	rotate(t_node **head, t_node **tail)
void	rev_rotate(t_node **head, t_node **tail)

#endif
