/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 22:25:56 by rvincent          #+#    #+#             */
/*   Updated: 2022/07/25 19:31:51 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_sorted(t_stack *stack_a)
{
	int	previous;
	int	i;

	previous = -2147483648;
	i = 0;
	while (stack_a)
	{
		if (stack_a->content < previous)
			return (0);
		i++;
		previous = stack_a->content;
		stack_a = stack_a->next;
	}
	return (1);
}

void	clear_list(t_stack **stact_stack)
{
	t_stack	*tmp;

	while (*stact_stack)
	{
		tmp = (*stact_stack)->next;
		free(*stact_stack);
		*stact_stack = tmp;
	}
}

void	print_list(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d ", stack->content);
		stack = stack->next;
	}
	ft_printf("\n");
}
