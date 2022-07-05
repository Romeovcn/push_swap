#include "push_swap.h"

int check_is_reverse_better(k_list *stack, int nbr)
{
	int position;
	int size;

	position = 0;
	size = get_stack_size(stack);
	while (stack && stack->content != nbr)
	{
		position++;
		stack = stack->next;
	}
	if ((size - position) < position)
		return 1;
	return 0; 	
}

void tester(k_list *stack_a)
{
	int previous;
	int i;

	i = 0;
	previous = -2147483648;
	while (stack_a)
	{
		if (stack_a->content < previous)
		{
			printf("%d IS BIGGER THAN %d ERROR\n", previous, stack_a->content);
			exit(0);
		}
		i++;
		previous = stack_a->content;
		stack_a = stack_a->next;
	}
	printf("SIZE=%d\n", i);
}

int	main(int argc, char **argv)
{
	k_list	*stack_a;
	k_list	*stack_b;
	t_move best;
	k_list *sorted_int;
	t_data data;

	sorted_int = NULL;
	stack_a = get_stack(argc, argv);
	stack_b = NULL;
	//get_data(stack_a, &data);

	//if (data.size > 100)
	//{
	//	sort_first_half(&stack_a, &stack_b, &data, &best, &sorted_int);
	//	while (get_stack_size(stack_b) != 0)
	//	{
	//		pa(&stack_a, &stack_b);
	//		ft_printf("pa\n");
	//	}
	//	sort_second_half(&stack_a, &stack_b, &data, &best, &sorted_int);
	//	put_second_half_back(&stack_a, &stack_b, &data, &best, &sorted_int);
	//	while (stack_a->content != data.smallest)	
	//	{
	//		rra(&stack_a, stack_a);
	//		ft_printf("rra\n");
	//	}
	//}
	//else
	//{
	//	while (get_stack_size(stack_a) != 2)
	//	{
	//		best = calculate_move_total(stack_a, stack_b, sorted_int, data);
	//		do_op(&stack_a, &stack_b, best);
	//		do_op_2(&stack_a, &stack_b, best);
	//		pb(&stack_a, &stack_b);
	//		ft_printf("pb\n");
	//	}

	//	if (stack_a->content > stack_a->next->content)
	//	{
	//		sa(stack_a);
	//		ft_printf("sa\n");
	//	}

	//	if (stack_b && check_is_reverse_better(stack_b, get_biggest(stack_b)))
	//		while (stack_b && stack_b->content != get_biggest(stack_b))
	//		{
	//			rrb(&stack_b, stack_b);
	//			ft_printf("rrb\n");
	//		}
	//	else
	//		while (stack_b && stack_b->content != get_biggest(stack_b))
	//		{
	//			rb(&stack_b, stack_b);
	//			ft_printf("rb\n");
	//		}

	//	while (get_stack_size(stack_b) != 0)
	//	{
	//		pa(&stack_a, &stack_b);
	//		ft_printf("pa\n");
	//	}
	//}

	//tester(stack_a);
	printf("---------------------------------------------\n");
	print_list(stack_a);
	printf("---------------------------------------------\n");
	print_list(stack_b);
	//clear_list(&stack_a);
	//clear_list(&stack_b);
}