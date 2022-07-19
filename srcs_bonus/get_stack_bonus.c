/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 22:26:00 by rvincent          #+#    #+#             */
/*   Updated: 2022/07/17 22:49:59 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	last = *lst;
	if (*lst)
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else
		*lst = new;
}

t_stack	*lstnew(int content)
{
	t_stack	*result;

	result = malloc(sizeof(t_stack));
	if (!result)
		return (0);
	result->content = content;
	result->next = NULL;
	return (result);
}

t_stack	*get_2_args_stack(char *stack_str)
{
	char	**stack_array;
	t_stack	*result;
	int		i;
	long	nbr;

	i = 0;
	result = NULL;
	stack_array = ft_split(stack_str, ' ');
	while (stack_array[i])
	{
		nbr = ft_atoi(stack_array[i]);
		check_error(result, nbr, stack_array[i]);
		lstadd_back(&result, lstnew(nbr));
		i++;
	}
	i = 0;
	while (stack_array[i])
		free(stack_array[i++]);
	free(stack_array);
	return (result);
}

t_stack	*get_multiple_args_stack(char **argv)
{
	t_stack	*result;
	int		i;
	long	nbr;

	i = 1;
	result = NULL;
	while (argv[i])
	{
		nbr = ft_atoi(argv[i]);
		check_error(result, nbr, argv[i]);
		lstadd_back(&result, lstnew(nbr));
		i++;
	}
	return (result);
}

t_stack	*get_stack(int argc, char **argv)
{
	t_stack	*result;

	if (argc == 1)
		exit(0);
	if (argc == 2)
		result = get_2_args_stack(argv[1]);
	else
		result = get_multiple_args_stack(argv);
	return (result);
}
