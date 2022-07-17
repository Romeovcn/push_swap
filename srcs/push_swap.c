/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:52:19 by rvincent          #+#    #+#             */
/*   Updated: 2022/07/17 19:25:19 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TO DO
// NORMINETTE

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_move	best;
	t_data	data;

	data.sorted_int = NULL;
	stack_a = get_stack(argc, argv);
	stack_b = NULL;
	get_data(stack_a, &data);
	if (!is_sorted(stack_a))
	{
		if (data.size > 100)
			sort_big_stack(&stack_a, &stack_b, &data, &best);
		else if (data.size <= 100 && data.size > 2)
			sort_medium_stack(&stack_a, &stack_b, &data, &best);
		else if (data.size == 2)
			sort_small_stack(&stack_a, &stack_b);
	}
	// tester(stack_a);
	// printf("---------------------------------------------\n");
	// print_list(stack_a);
	// printf("---------------------------------------------\n");
	// print_list(stack_b);
	// printf("---------------------------------------------\n");
	// print_list(data.sorted_int);
	clear_list(&stack_a);
	clear_list(&data.sorted_int);
}
