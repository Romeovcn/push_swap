/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:29:16 by rvincent          #+#    #+#             */
/*   Updated: 2022/07/11 18:49:23 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_small_stack(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
	{
		sa(*stack_a);
		ft_printf("sa\n");
	}
}
