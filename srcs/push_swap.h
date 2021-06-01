#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_node
{
	int		nbr;
	struct s_node	*next;
	struct s_node	*prev;
	int				index;
}			t_node;

typedef struct		s_stack
{
	t_node		*a_head;
	t_node		*a_tail;
	t_node		*b_head;
	t_node		*b_tail;
	t_node		*pivot1;
	t_node		*pivot2;
	t_node		*pivot3;
	t_node		*pivot4;
	t_node		*pivot5;
	t_node		*pivot6;
	t_node		*pivot7;
	t_node		*pivot8;
	t_node		*pivot9;
	t_node		*pivot10;
	int			count;
}				t_stack;

t_stack		*create_stack(int ac, char **av);
void    	add_index(t_stack *stack, int ac);
void    	solve(t_stack *stack, int ac);
void        big_sort_split(t_stack *stack, int min, int max);
void        big_sort_swap_first(t_stack *stack, int min, int max);
void        big_sort_swap_end(t_stack *stack, int min, int max);

void     	big_sort_swap(t_stack *stack, int min, int max);

void		push(char *line, t_stack *stack);
void		swap(t_node **head);
void		rotate(t_node **head, t_node **tail);
void		rev_rotate(t_node **head, t_node **tail);

void		swapper(char *line, t_stack *stack);
void		rotater(char *line, t_stack *stack);
void		rev_rotater(char *line, t_stack *stack);

int			ft_strcmp(const char *s1, const char *s2);
long long	ft_atol(const char *nptr);
void		free_node(t_node *stack);

#endif
