#include "push_swap.h"

void	push(char *line, t_stack *stack)
{
	t_node *tmp;

	if (*(line + 1) == 'a')
	{
		if (stack->b_head == NULL)
			return ;
		tmp = stack->b_head;
		stack->b_head = stack->b_head->next;
		if (stack->b_head)
			(stack->b_head)->prev = NULL;
		if (stack->a_head)
			(stack->a_head)->prev = tmp;
		else
			stack->a_tail = tmp;
		tmp->next = stack->a_head;
		stack->a_head = tmp;
		stack->a_head->prev = NULL;
		write(1, "pa\n", 3);
		stack->count += 1;
	}
	if (*(line + 1) == 'b')
	{
		if (stack->a_head == NULL)
			return ;
		tmp = stack->a_head;
		stack->a_head = stack->a_head->next;
		if (stack->a_head)
			(stack->a_head)->prev = NULL;
		if (stack->b_head)
			(stack->b_head)->prev = tmp;
		else
			stack->b_tail = tmp;
		tmp->next = stack->b_head;
		stack->b_head = tmp;
		stack->b_head->prev = NULL;
		write(1, "pb\n", 3);
		stack->count += 1;
	}
}

void	swap(t_node **head)
{
	t_node *tmp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	tmp->prev = *head;
	(*head)->next = tmp;
	(*head)->prev = NULL;
}

void	rotate(t_node **head, t_node **tail)
{
	if (*head == NULL || *tail == NULL || (*head)->next == NULL)
		return ;
	(*tail)->next = *head;
	(*head)->prev = *tail;
	*head = (*head)->next;
	(*head)->prev = NULL;
	*tail = (*tail)->next;
	(*tail)->next = NULL;
}

void	rev_rotate(t_node **head, t_node **tail)
{
	if (*head == NULL || *tail == NULL || (*tail)->prev == NULL)
		return ;
	(*head)->prev = *tail;
	(*tail)->next = *head;
	*head = *tail;
	*tail = (*tail)->prev;
	(*tail)->next = NULL;
	(*head)->prev = NULL;
}