/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:26:43 by rvincent          #+#    #+#             */
/*   Updated: 2022/07/11 18:43:10 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_move_extract(t_stack *stack, int nbr, t_move *current)
{
	t_stack	*head;
	int		position;
	int		size;

	head = stack;
	position = 0;
	size = 0;
	while (head)
	{
		size++;
		head = head->next;
	}
	head = stack;
	while (head && nbr != head->content)
	{
		position++;
		head = head->next;
	}
	if ((size - position) < position)
	{
		current->rra = (size - position);
		return (size - position);
	}
	current->ra = position;
	return (position);
}

int	find_first_smallest(t_stack *stack, int nbr)
{
	int	next_smallest;

	next_smallest = nbr;
	while (stack)
	{
		if (stack->content < nbr)
		{
			next_smallest = stack->content;
			break ;
		}
		stack = stack->next;
	}
	return (next_smallest);
}

int	find_biggest(t_stack *stack, int nbr)
{
	int	biggest;

	biggest = nbr;
	while (stack)
	{
		if (stack->content > nbr && stack->content > biggest)
			biggest = stack->content;
		stack = stack->next;
	}
	return (biggest);
}

int	find_next_smallest(t_stack *stack, int smallest, int nbr)
{
	while (stack)
	{
		if (stack->content < nbr && stack->content > smallest)
			smallest = stack->content;
		stack = stack->next;
	}
	return (smallest);
}

int	get_move(t_stack *stack, int nbr, t_move *current)
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
		current->rrb = (size - position);
		return (size - position);
	}
	current->rb = position;
	return (position);
}

int	calculate_move_insert(t_stack *stack, int nbr, t_move *current)
{
	int	smallest;
	int	biggest;
	int	move;

	smallest = find_first_smallest(stack, nbr);
	biggest = find_biggest(stack, nbr);
	if (smallest != nbr)
	{
		smallest = find_next_smallest(stack, smallest, nbr);
		move = get_move(stack, smallest, current);
	}
	else
		move = get_move(stack, biggest, current);
	return (move);
}

t_move	calculate_move_total(t_stack *stack_a, t_stack *stack_b, t_data data)
{
	t_stack	*head;
	t_move	current;
	t_move	best;

	head = stack_a;
	init_struct(&best);
	best.rra = 2147483647;
	while (stack_a)
	{
		init_struct(&current);
		current.nbr = stack_a->content;
		calculate_move_extract(head, stack_a->content, &current);
		calculate_move_insert(stack_b, stack_a->content, &current);
		reverse_check(&current);
		if (get_total_move(&current) < get_total_move(&best)
			&& stack_a->content != data.biggest
			&& stack_a->content != data.second_biggest
			&& stack_a->content != data.third_biggest && data.size <= 100)
			best = current;
		if (get_total_move(&current) < get_total_move(&best)
			&& check_int_already_sorted(current.nbr, data.sorted_int)
			&& data.size > 100)
			best = current;
		stack_a = stack_a->next;
	}
	return (best);
}
