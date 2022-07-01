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

void do_op(k_list **stack_a, k_list **stack_b, t_move best, int *action_count)
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

void do_op2(k_list **stack_a, k_list **stack_b, t_move best, int *action_count)
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

int get_second_biggest(k_list *stack, int biggest)
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

int get_smallest(k_list *stack)
{
	int smallest;

	smallest = 2147483647;
	while (stack)
	{
		if (stack->content < smallest)
			smallest = stack->content;
		stack = stack->next;
	}
	return smallest;
}

int	main(int argc, char **argv)
{
	k_list	*stack_a;
	k_list	*stack_b;
	int action_count;
	t_move best;
	int biggest;
	int second_biggest;
	int smallest;

	action_count = 0;
	stack_a = get_stack(argv[1]);
	stack_b = get_stack("");
	biggest = get_biggest(stack_a);
	second_biggest = get_second_biggest(stack_a, biggest);

	while (get_stack_size(stack_a) != 2)
	{
		best = calculate_move_total(stack_a, stack_b, biggest, second_biggest);
		do_op(&stack_a, &stack_b, best, &action_count);
		do_op2(&stack_a, &stack_b, best, &action_count);
		pb(&stack_a, &stack_b);
		ft_printf("pb\n");
	}

	biggest = get_biggest(stack_b);
	if (stack_a->content >stack_a->next->content)
	{
		sa(stack_a);
		ft_printf("sa\n");
	}
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
	// printf("\n");
	// print_list(stack_b);
	// printf("%d\n", action_count);
	clear_list(&stack_a);
	clear_list(&stack_b);
}