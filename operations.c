#include "push_swap.h"

void	clear_list(k_list **stack_list, char **stack)
{
	k_list	*tmp;
	int		i;

	i = 0;
	while (*stack_list)
	{
		tmp = (*stack_list)->next;
		free(*stack_list);
		*stack_list = tmp;
	}
	while (stack[i])
		free(stack[i++]);
	free(stack);
}

void	sa(k_list *stack_a, int *count)
{
	int	tmp;

	if (!stack_a)
		return ;
	tmp = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = tmp;
	(*count) = (*count) + 1;
}

// void	sb(k_list *stack_b)
// {
// 	int	tmp;

// 	if (!stack_b)
// 		return ;
// 	tmp = stack_b->content;
// 	stack_b->content = stack_b->next->content;
// 	stack_b->next->content = tmp;
// }

// void	ss(k_list *stack_a, k_list *stack_b)
// {
// 	sa(stack_a);
// 	sb(stack_b);
// }

void	pa(k_list **stack_a, k_list **stack_b, int *count)
{
	k_list	*tmp;

	if (!*stack_b)
		return ;
	tmp = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = tmp;
	(*count) = (*count) + 1;
}

void	pb(k_list **stack_a, k_list **stack_b, int *count)
{
	k_list	*tmp;

	if (!*stack_a)
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	*stack_b = *stack_a;
	*stack_a = tmp;
	(*count) = (*count) + 1;
}

void	ra(k_list **stack_a_ptr, k_list *stack_a, int *count)
{
	k_list	*tmp;

	if (!stack_a)
		return ;
	tmp = stack_a;
	while (stack_a->next)
		stack_a = stack_a->next;
	stack_a->next = tmp;
	*stack_a_ptr = (*stack_a_ptr)->next;
	tmp->next = NULL;
	(*count) = (*count) + 1;
}

void	rb(k_list **stack_b_ptr, k_list *stack_b, int *count)
{
	k_list	*tmp;

	if (!stack_b)
		return ;
	tmp = stack_b;
	while (stack_b->next)
		stack_b = stack_b->next;
	stack_b->next = tmp;
	*stack_b_ptr = (*stack_b_ptr)->next;
	tmp->next = NULL;
	(*count) = (*count) + 1;
}

void	rr(k_list **stack_a_ptr, k_list **stack_b_ptr, int *count)
{
	ra(stack_a_ptr, *stack_a_ptr, count);
	rb(stack_b_ptr, *stack_b_ptr, count);
	(*count) = (*count) - 1;
}

void	rra(k_list **stack_a_ptr, k_list *stack_a, int *count)
{
	k_list	*tmp;

	if (!stack_a)
		return ;
	while (stack_a->next->next)
		stack_a = stack_a->next;
	tmp = stack_a->next;
	stack_a->next = NULL;
	tmp->next = *stack_a_ptr;
	*stack_a_ptr = tmp;
	(*count) = (*count) + 1;
}

void	rrb(k_list **stack_b_ptr, k_list *stack_b, int *count)
{
	k_list	*tmp;

	if (!stack_b)
		return ;
	while (stack_b->next->next)
		stack_b = stack_b->next;
	tmp = stack_b->next;
	stack_b->next = NULL;
	tmp->next = *stack_b_ptr;
	*stack_b_ptr = tmp;
	(*count) = (*count) + 1;
}

void	rrr(k_list **stack_a_ptr, k_list **stack_b_ptr, int *count)
{
	rra(stack_a_ptr, *stack_a_ptr, count);
	rrb(stack_b_ptr, *stack_b_ptr, count);
	(*count) = (*count) - 1;
}