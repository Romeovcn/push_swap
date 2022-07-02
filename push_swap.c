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

void do_op(k_list **stack_a, k_list **stack_b, t_move best)
{
	while (best.rra--)
	{
		rra(stack_a, *stack_a);
		ft_printf("rra\n");
	}
	while (best.rrb--)
	{
		rrb(stack_b, *stack_b);
		ft_printf("rrb\n");
	}
	while (best.rrr--)
	{
		rrr(stack_a, stack_b);
		ft_printf("rrr\n");
	}
}

void do_op2(k_list **stack_a, k_list **stack_b, t_move best)
{
	while (best.ra--)
	{
		ra(stack_a, *stack_a);
		ft_printf("ra\n");
	}
	while (best.rb--)
	{
		rb(stack_b, *stack_b);
		ft_printf("rb\n");
	}
	while (best.rr--)
	{
		rr(stack_a, stack_b);
		ft_printf("rr\n");
	}
}

int get_biggest(k_list *stack)
{
	int biggest;

	biggest = -2147483648;
	while (stack)
	{
		if (stack->content > biggest)
			biggest = stack->content;
		stack = stack->next;
	}
	return biggest;
}

int get_next_biggest(k_list *stack, int biggest)
{
	int second_biggest;

	second_biggest = -2147483648;
	while (stack)
	{
		if (stack->content > second_biggest && stack->content < biggest)
			second_biggest = stack->content;
		stack = stack->next;
	}
	return second_biggest;
}

int	main(int argc, char **argv)
{
	k_list	*stack_a;
	k_list	*stack_b;
	t_move best;
	int biggest;
	int second_biggest;
	int third_biggest;

	stack_a = get_stack(argv[1]);
	stack_b = get_stack("");
	biggest = get_biggest(stack_a);
	second_biggest = get_next_biggest(stack_a, biggest);
	third_biggest = get_next_biggest(stack_a, second_biggest);


	while (get_stack_size(stack_a) != 3)
	{
		best = calculate_move_total(stack_a, stack_b, biggest, second_biggest, third_biggest);
		do_op(&stack_a, &stack_b, best);
		do_op2(&stack_a, &stack_b, best);
		pb(&stack_a, &stack_b);
		ft_printf("pb\n");
	}

	if (stack_a->content == biggest)
	{
		ra(&stack_a, stack_a);
		ft_printf("ra\n");
	}
	if (stack_a->next->content == biggest)
	{
		rra(&stack_a, stack_a);
		ft_printf("rra\n");
	}
	if (stack_a->content >stack_a->next->content)
	{
		sa(stack_a);
		ft_printf("sa\n");
	}

	biggest = get_biggest(stack_b);
	if (check_is_reverse_better(stack_b, biggest))
		while (stack_b->content != biggest)
		{
			rrb(&stack_b, stack_b);
			ft_printf("rrb\n");
		}
	else
		while (stack_b->content != biggest)
		{
			rb(&stack_b, stack_b);
			ft_printf("rb\n");
		}
	while (get_stack_size(stack_b) != 0)
	{
		pa(&stack_a, &stack_b);
		ft_printf("pa\n");
	}

	// print_list(stack_a);
	// printf("---------------------------------------------\n");
	// print_list(stack_b);
	clear_list(&stack_a);
	clear_list(&stack_b);
}