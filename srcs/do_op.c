/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:23:26 by rvincent          #+#    #+#             */
/*   Updated: 2022/07/17 19:23:35 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_op(t_stack **stack_a, t_stack **stack_b, t_move best)
{
	while (best.rra--)
	{
		rra(stack_a);
		ft_printf("rra\n");
	}
	while (best.rrb--)
	{
		rrb(stack_b);
		ft_printf("rrb\n");
	}
	while (best.rrr--)
	{
		rrr(stack_a, stack_b);
		ft_printf("rrr\n");
	}
}

void	do_op_2(t_stack **stack_a, t_stack **stack_b, t_move best)
{
	while (best.ra--)
	{
		ra(stack_a);
		ft_printf("ra\n");
	}
	while (best.rb--)
	{
		rb(stack_b);
		ft_printf("rb\n");
	}
	while (best.rr--)
	{
		rr(stack_a, stack_b);
		ft_printf("rr\n");
	}
}
