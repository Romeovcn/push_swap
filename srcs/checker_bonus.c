/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:51:10 by rvincent          #+#    #+#             */
/*   Updated: 2022/07/17 21:44:19 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

// get stack 1 2 3 4 || "1 2 3 4"

int	check_matching_str(char *str, char *str_to_find)
{
	int	size;
	int	i;

	size = ft_strlen(str);
	i = 0;
	while (str[i] && str[i] == str_to_find[i])
		i++;
	if (i == size && !str[i] && !str_to_find[i])
		return (1);
	return (0);
}

int	check_move(char *line)
{
	if (check_matching_str("sa\n", line) || check_matching_str("sb\n", line)
		|| check_matching_str("ss\n", line) || check_matching_str("ra\n", line)
		|| check_matching_str("rb\n", line) || check_matching_str("rr\n", line)
		|| check_matching_str("rra\n", line) || check_matching_str("rrb\n",
			line) || check_matching_str("rrr\n", line)
		|| check_matching_str("pa\n", line) || check_matching_str("pb\n", line))
		return (0);
	return (1);
}

void	do_op_checker(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (check_matching_str("sa\n", line))
		sa(*stack_a);
	else if (check_matching_str("sb\n", line))
		sb(*stack_b);
	else if (check_matching_str("ss\n", line))
		ss(*stack_a, *stack_b);
	else if (check_matching_str("ra\n", line))
		ra(stack_a);
	else if (check_matching_str("rb\n", line))
		rb(stack_b);
	else if (check_matching_str("rr\n", line))
		rr(stack_a, stack_b);
	else if (check_matching_str("rra\n", line))
		rra(stack_a);
	else if (check_matching_str("rrb\n", line))
		rrb(stack_b);
	else if (check_matching_str("rrr\n", line))
		rrr(stack_a, stack_b);
	else if (check_matching_str("pa\n", line))
		pa(stack_a, stack_b);
	else if (check_matching_str("pb\n", line))
		pb(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		fd;
	char	*line;

	stack_a = get_stack(argc, argv);
	stack_b = NULL;
	fd = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (check_move(line))
		{
			ft_printf("Error\n");
			return (1);
		}
		do_op_checker(&stack_a, &stack_b, line);
		line = get_next_line(fd);
	}
	if (is_sorted(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	clear_list(&stack_a);
	free(line);
}
