#include "push_swap.h"

void sort_first_half(k_list **stack_a, k_list **stack_b, t_data *data, t_move *best, k_list **sorted_int)
{
	while (get_stack_size(*stack_b) != data->size / 2)
	{
		*best = calculate_move_total(*stack_a, *stack_b, *sorted_int, *data);
		lstadd_back(sorted_int, lstnew(best->nbr));
		do_op(stack_a, stack_b, *best);
		do_op_2(stack_a, stack_b, *best);
		pb(stack_a, stack_b);
		//ft_printf("pb\n");
	}
}

void sort_second_half(k_list **stack_a, k_list **stack_b, t_data *data, t_move *best, k_list **sorted_int)
{
	while (get_stack_size(*stack_b) != data->size - (data->size / 2))
	{
		*best = calculate_move_total(*stack_a, *stack_b, *sorted_int, *data);
		lstadd_back(sorted_int, lstnew(best->nbr));
		do_op(stack_a, stack_b, *best);
		do_op_2(stack_a, stack_b, *best);
		pb(stack_a, stack_b);
		//ft_printf("pb\n");
	}
}

void put_second_half_back(k_list **stack_a, k_list **stack_b, t_data *data, t_move *best, k_list **sorted_int)
{
	while (get_stack_size(*stack_b) != 0)
	{
		*best = calculate_insert_stack_a((*stack_b)->content, *stack_a);
		do_op(stack_a, stack_b, *best);
		do_op_2(stack_a, stack_b, *best);
		pa(stack_a, stack_b);
		ft_printf("pa\n");
	}
}