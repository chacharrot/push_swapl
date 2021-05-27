#include "push_swap.h"

void	push(t_node **from_head, t_node **to_head, t_node **to_tail)
{
	t_node *tmp;

	if (*from_head == NULL)
		return ;
	tmp = *from_head;
	*from_head = (*from_head)->next;
	if (*from_head)
		(*from_head)->prev = NULL;
	if (*to_head)
		(*to_head)->prev = tmp;
	else
		*to_tail = tmp;
	tmp->next = *to_head;
	*to_head = tmp;
	(*to_head)->prev = NULL;
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