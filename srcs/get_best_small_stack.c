/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best_small_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:54:38 by rvincent          #+#    #+#             */
/*   Updated: 2022/07/11 18:46:57 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_first_bigger(t_stack *stack, int nbr)
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

int	get_next_bigger(t_stack *stack, int nbr)
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

void	get_move_stack_a(t_stack *stack, int nbr, t_move *current)
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
		return ;
	}
	current->ra = position;
}

t_move	calculate_insert_stack_a(int nbr, t_stack *stack)
{
	t_move	best;
	int		next_bigger;
	int		smallest;

	next_bigger = get_next_bigger(stack, nbr);
	smallest = get_smallest(stack);
	init_struct(&best);
	best.nbr = nbr;
	if (next_bigger != nbr)
		get_move_stack_a(stack, next_bigger, &best);
	else
		get_move_stack_a(stack, smallest, &best);
	return (best);
}
