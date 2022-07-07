/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:46:20 by rvincent          #+#    #+#             */
/*   Updated: 2022/07/06 17:46:30 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(k_list *stack_a)
{
	int	tmp;

	if (!stack_a)
		return ;
	tmp = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = tmp;
}

void	pa(k_list **stack_a, k_list **stack_b)
{
	k_list	*tmp;

	if (!*stack_b)
		return ;
	tmp = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = tmp;
}

void	pb(k_list **stack_a, k_list **stack_b)
{
	k_list	*tmp;

	if (!*stack_a)
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	*stack_b = *stack_a;
	*stack_a = tmp;
}

void	ra(k_list **stack_a_ptr, k_list *stack_a)
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
}

void	rb(k_list **stack_b_ptr, k_list *stack_b)
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
}

void	rr(k_list **stack_a_ptr, k_list **stack_b_ptr)
{
	ra(stack_a_ptr, *stack_a_ptr);
	rb(stack_b_ptr, *stack_b_ptr);
}
