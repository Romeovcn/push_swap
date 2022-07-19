/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:43:04 by rvincent          #+#    #+#             */
/*   Updated: 2022/07/17 22:25:44 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rrr(t_stack **stack_a_ptr, t_stack **stack_b_ptr)
{
	rra(stack_a_ptr);
	rrb(stack_b_ptr);
}

void	rr(t_stack **stack_a_ptr, t_stack **stack_b_ptr)
{
	ra(stack_a_ptr);
	rb(stack_b_ptr);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
