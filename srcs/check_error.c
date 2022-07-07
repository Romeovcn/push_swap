/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:08:43 by rvincent          #+#    #+#             */
/*   Updated: 2022/07/07 23:01:52 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_max_int(char *nbr_str, long nbr)
{
	int	nbr_char;
	int	i;

	nbr_char = 0;
	i = 0;
	while (nbr_str[nbr_char])
		nbr_char++;
	if (nbr_char > 10 || nbr > 2147483647 || nbr < -2147483648)
		return (1);
	return (0);
}

int	check_duplicate(k_list *stack, long nbr)
{
	while (stack)
	{
		if (stack->content == nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	check_digit_error(char *nbr)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (nbr[size])
		size++;
	if (nbr[i] == '-' && size > 1)
		i++;
	else if (nbr[i] == '-' && size == 1)
		return (1);
	while (nbr[i])
	{
		if (nbr[i] < '0' || nbr[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	check_error(k_list *stack, long nbr, char *argv)
{
	if (check_max_int(argv, nbr) || check_duplicate(stack, nbr)
		|| check_digit_error(argv))
	{
		ft_printf("Error\n");
		exit(0);
	}
	return ;
}