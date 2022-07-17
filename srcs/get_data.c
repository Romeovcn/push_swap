/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:36:42 by rvincent          #+#    #+#             */
/*   Updated: 2022/07/11 18:37:53 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	get_biggest(t_stack *stack)
{
	int	biggest;

	biggest = -2147483648;
	while (stack)
	{
		if (stack->content > biggest)
			biggest = stack->content;
		stack = stack->next;
	}
	return (biggest);
}

int	get_next_biggest(t_stack *stack, int biggest)
{
	int	second_biggest;

	second_biggest = -2147483648;
	while (stack)
	{
		if (stack->content < biggest && stack->content > second_biggest)
			second_biggest = stack->content;
		stack = stack->next;
	}
	return (second_biggest);
}

int	get_smallest(t_stack *stack)
{
	int	smallest;

	smallest = 2147483647;
	while (stack)
	{
		if (stack->content < smallest)
			smallest = stack->content;
		stack = stack->next;
	}
	return (smallest);
}

void	get_data(t_stack *stack_a, t_data *data)
{
	data->size = get_stack_size(stack_a);
	data->smallest = get_smallest(stack_a);
	data->biggest = get_biggest(stack_a);
	data->second_biggest = get_next_biggest(stack_a, data->biggest);
	if (get_stack_size(stack_a) > 2)
		data->third_biggest = get_next_biggest(stack_a, data->second_biggest);
}