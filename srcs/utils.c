/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:36:35 by rvincent          #+#    #+#             */
/*   Updated: 2022/07/11 18:38:33 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d ", stack->content);
		stack = stack->next;
	}
	ft_printf("\n");
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

int	check_is_reverse_better(t_stack *stack, int nbr)
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
		return (1);
	return (0);
}

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

void push_stack_b_to_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	while (get_stack_size(*stack_b) != 0)
	{
		pa(stack_a, stack_b);
		ft_printf("pa\n");
	}
}

void	tester(t_stack *stack_a)
{
	int	previous;
	int	i;

	previous = -2147483648;
	i = 0;
	while (stack_a)
	{
		if (stack_a->content < previous)
			printf("%d IS BIGGER THAN %d ERROR\n", previous, stack_a->content);
		i++;
		previous = stack_a->content;
		stack_a = stack_a->next;
	}
	printf("SIZE=%d\n", i);
}
