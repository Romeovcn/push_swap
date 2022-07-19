/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best_big_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:26:43 by rvincent          #+#    #+#             */
/*   Updated: 2022/07/19 18:58:14 by rvincent         ###   ########.fr       */
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

int	find_smallest(t_stack *stack, int nbr)
{
	int		smallest;
	t_stack	*head;

	smallest = nbr;
	head = stack;
	while (stack && smallest == nbr)
	{
		if (stack->content < smallest)
			smallest = stack->content;
		stack = stack->next;
	}
	while (head)
	{
		if (head->content > smallest && head->content < nbr)
			smallest = head->content;
		head = head->next;
	}
	return (smallest);
}

int	calculate_move_insert(t_stack *stack, int nbr, t_move *current)
{
	int	smallest;
	int	biggest;
	int	move;

	smallest = find_smallest(stack, nbr);
	biggest = get_biggest(stack);
	if (smallest != nbr)
		move = get_move(stack, smallest, current);
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
	init_struct(&best, 0);
	best.rra = 2147483647;
	while (stack_a)
	{
		init_struct(&current, stack_a->content);
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
