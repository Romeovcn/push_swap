/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:26:43 by rvincent          #+#    #+#             */
/*   Updated: 2022/07/08 23:47:04 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_move_extract(k_list *stack, int nbr, t_move *current)
{
	k_list	*head;
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

int	find_first_smallest(k_list *stack, int nbr)
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

int	find_biggest(k_list *stack, int nbr)
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

int	find_next_smallest(k_list *stack, int smallest, int nbr)
{
	while (stack)
	{
		if (stack->content < nbr && stack->content > smallest)
			smallest = stack->content;
		stack = stack->next;
	}
	return (smallest);
}

int	get_move(k_list *stack, int nbr, t_move *current)
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

int	calculate_move_insert(k_list *stack, int nbr, t_move *current)
{
	int		smallest;
	int		biggest;
	int		move;

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

void	init_struct(t_move *current)
{
	current->rra = 0;
	current->ra = 0;
	current->rrr = 0;
	current->rr = 0;
	current->rrb = 0;
	current->rb = 0;
	current->total = 0;
}

int	get_total_move(t_move *current)
{
	int	total;

	total = current->rra + current->ra + current->rrr + current->rr
		+ current->rrb + current->rb;
	current->total = total;
	return (total);
}

void	reverse_check(t_move *current)
{
	while (current->ra >= 1 && current->rb >= 1)
	{
		current->ra--;
		current->rb--;
		current->rr++;
	}
	while (current->rra >= 1 && current->rrb >= 1)
	{
		current->rra--;
		current->rrb--;
		current->rrr++;
	}
}

int	check_int_already_sorted(int nbr, k_list *sorted_int)
{
	while (sorted_int)
	{
		if (sorted_int->content == nbr)
			return (0);
		sorted_int = sorted_int->next;
	}
	return (1);
}

t_move	calculate_move_total(k_list *stack_a, k_list *stack_b, t_data data)
{
	k_list	*head;
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
			&& stack_a->content != data.second_biggest && data.size <= 100)
			best = current;
		if (get_total_move(&current) < get_total_move(&best)
			&& check_int_already_sorted(current.nbr, data.sorted_int)
			&& data.size > 100)
			best = current;
		stack_a = stack_a->next;
	}
	return (best);
}
