/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:28:23 by rvincent          #+#    #+#             */
/*   Updated: 2022/07/08 21:47:20 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_first_half(k_list **stack_a, k_list **stack_b, t_data *data,
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
	while (get_stack_size(*stack_b) != 0)
	{
		pa(stack_a, stack_b);
		ft_printf("pa\n");
	}
}

void	sort_second_half(k_list **stack_a, k_list **stack_b, t_data *data,
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

void	put_second_half_back(k_list **stack_a, k_list **stack_b, t_data *data,
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
		rra(stack_a, *stack_a);
		ft_printf("rra\n");
	}
}
