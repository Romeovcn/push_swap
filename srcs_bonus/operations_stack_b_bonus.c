/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_stack_b_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:46:33 by rvincent          #+#    #+#             */
/*   Updated: 2022/07/25 19:13:07 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!*stack_a)
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	*stack_b = *stack_a;
	*stack_a = tmp;
}

void	rb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*head;

	if (!*stack_b)
		return ;
	head = *stack_b;
	tmp = *stack_b;
	while (head->next)
		head = head->next;
	head->next = tmp;
	*stack_b = tmp->next;
	tmp->next = NULL;
}

void	rrb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*head;

	if (!*stack_b)
		return ;
	head = *stack_b;
	while (head->next->next)
		head = head->next;
	tmp = head->next;
	head->next = NULL;
	tmp->next = *stack_b;
	*stack_b = tmp;
}

void	sb(t_stack *stack_b)
{
	int	tmp;

	if (!stack_b || !stack_b->next)
		return ;
	tmp = stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->next->content = tmp;
}
