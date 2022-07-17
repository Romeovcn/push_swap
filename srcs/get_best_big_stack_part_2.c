/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best_big_stack_part_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:41:05 by rvincent          #+#    #+#             */
/*   Updated: 2022/07/11 18:51:41 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	check_int_already_sorted(int nbr, t_stack *sorted_int)
{
	while (sorted_int)
	{
		if (sorted_int->content == nbr)
			return (0);
		sorted_int = sorted_int->next;
	}
	return (1);
}

int	get_total_move(t_move *current)
{
	int	total;

	total = current->rra + current->ra + current->rrr + current->rr
		+ current->rrb + current->rb;
	current->total = total;
	return (total);
}
