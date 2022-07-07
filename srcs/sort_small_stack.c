/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:29:16 by rvincent          #+#    #+#             */
/*   Updated: 2022/07/06 17:45:29 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_in_stack_b(k_list **stack_a, k_list **stack_b, t_data *data,
		t_move *best)
{
	while (get_stack_size(*stack_a) != 2)
	{
		*best = calculate_move_total(*stack_a, *stack_b, *data);
		do_op(stack_a, stack_b, *best);
		do_op_2(stack_a, stack_b, *best);
		pb(stack_a, stack_b);
		ft_printf("pb\n");
	}
	if ((*stack_a)->content > (*stack_a)->next->content)
	{
		sa(*stack_a);
		ft_printf("sa\n");
	}
}

void	push_back_stack_a(k_list **stack_a, k_list **stack_b, t_data *data,
		t_move *best)
{
	if (*stack_b && check_is_reverse_better(*stack_b, get_biggest(*stack_b)))
	{
		while (*stack_b && (*stack_b)->content != get_biggest(*stack_b))
		{
			rrb(stack_b, *stack_b);
			ft_printf("rrb\n");
		}
	}
	else
	{
		while (*stack_b && (*stack_b)->content != get_biggest(*stack_b))
		{
			rb(stack_b, *stack_b);
			ft_printf("rb\n");
		}
	}
	while (get_stack_size(*stack_b) != 0)
	{
		pa(stack_a, stack_b);
		ft_printf("pa\n");
	}
}
