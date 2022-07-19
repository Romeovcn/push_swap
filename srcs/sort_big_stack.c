/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:28:23 by rvincent          #+#    #+#             */
/*   Updated: 2022/07/17 22:52:25 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_first_half(t_stack **stack_a, t_stack **stack_b, t_data *data,
		t_move *best)
{
	while (get_stack_size(*stack_b) != data->size / 2)
	{
		*best = calculate_move_total(*stack_a, *stack_b, *data);
		lstadd_back(&data->sorted_int, lstnew(best->nbr));
		do_op(stack_a, stack_b, *best);
		do_op_2(stack_a, stack_b, *best);
		pb(stack_a, stack_b);
		ft_printf("pb\n");
	}
}

void	sort_second_half(t_stack **stack_a, t_stack **stack_b, t_data *data,
		t_move *best)
{
	while (get_stack_size(*stack_b) != data->size - (data->size / 2))
	{
		*best = calculate_move_total(*stack_a, *stack_b, *data);
		do_op(stack_a, stack_b, *best);
		do_op_2(stack_a, stack_b, *best);
		pb(stack_a, stack_b);
		ft_printf("pb\n");
	}
}

void	put_second_half_back(t_stack **stack_a, t_stack **stack_b, t_data *data,
		t_move *best)
{
	while (get_stack_size(*stack_b) != 0)
	{
		*best = calculate_insert_stack_a((*stack_b)->content, *stack_a);
		do_op(stack_a, stack_b, *best);
		do_op_2(stack_a, stack_b, *best);
		pa(stack_a, stack_b);
		ft_printf("pa\n");
	}
	while ((*stack_a)->content != data->smallest)
	{
		rra(stack_a);
		ft_printf("rra\n");
	}
}

void	sort_big_stack(t_stack **stack_a, t_stack **stack_b, t_data *data,
		t_move *best)
{
	sort_first_half(stack_a, stack_b, data, best);
	push_stack_b_to_stack_a(stack_a, stack_b);
	sort_second_half(stack_a, stack_b, data, best);
	put_second_half_back(stack_a, stack_b, data, best);
}
