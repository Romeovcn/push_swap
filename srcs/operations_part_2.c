/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:46:33 by rvincent          #+#    #+#             */
/*   Updated: 2022/07/06 18:46:24 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(k_list **stack_a_ptr, k_list *stack_a)
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
}

void	rrb(k_list **stack_b_ptr, k_list *stack_b)
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
}

void	rrr(k_list **stack_a_ptr, k_list **stack_b_ptr)
{
	rra(stack_a_ptr, *stack_a_ptr);
	rrb(stack_b_ptr, *stack_b_ptr);
}
