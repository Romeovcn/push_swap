/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ordered_b_to_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:54:38 by rvincent          #+#    #+#             */
/*   Updated: 2022/07/06 17:55:39 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_first_bigger(k_list *stack, int nbr)
{
	int	bigger;

	bigger = nbr;
	while (stack)
	{
		if (stack->content > bigger)
		{
			bigger = stack->content;
			return (bigger);
		}
		stack = stack->next;
	}
	return (bigger);
}

int	get_next_bigger(k_list *stack, int nbr)
{
	int	next_bigger;

	next_bigger = get_first_bigger(stack, nbr);
	while (stack)
	{
		if (stack->content > nbr && stack->content < next_bigger)
			next_bigger = stack->content;
		stack = stack->next;
	}
	return (next_bigger);
}

int	get_move_stack_a(k_list *stack, int nbr, t_move *current)
{
	int	position;
	int	size;

	position = 0;
	size = get_stack_size(stack);
	while (stack && stack->content != nbr)
	{
		position++;
		stack = stack->next;
	}
	if ((size - position) < position)
	{
		current->rra = (size - position);
		return (size - position);
	}
	current->ra = position;
	return (position);
}

t_move	calculate_insert_stack_a(int nbr, k_list *stack)
{
	t_move	best;
	int		move;
	int		size;
	int		next_bigger;
	int		smallest;

	size = get_stack_size(stack);
	next_bigger = get_next_bigger(stack, nbr);
	smallest = get_smallest(stack);
	init_struct(&best);
	best.nbr = nbr;
	if (next_bigger != nbr)
		move = get_move_stack_a(stack, next_bigger, &best);
	else
		move = get_move_stack_a(stack, smallest, &best);
	return (best);
}
