/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_stack_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:46:20 by rvincent          #+#    #+#             */
/*   Updated: 2022/07/17 19:20:17 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!*stack_b)
		return ;
	tmp = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = tmp;
}

void	ra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*head;

	if (!*stack_a)
		return ;
	head = *stack_a;
	tmp = *stack_a;
	while (head->next)
		head = head->next;
	head->next = tmp;
	*stack_a = tmp->next;
	tmp->next = NULL;
}

void	rra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*head;

	if (!*stack_a)
		return ;
	head = *stack_a;
	while (head->next->next)
		head = head->next;
	tmp = head->next;
	head->next = NULL;
	tmp->next = *stack_a;
	*stack_a = tmp;
}

void	sa(t_stack *stack_a)
{
	int	tmp;

	if (!stack_a)
		return ;
	tmp = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = tmp;
}
