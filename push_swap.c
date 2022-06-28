#include "push_swap.h"

k_list	*get_stack(char **stack)
{
	k_list	*result;
	int		i;
	int		nbr;

	i = 0;
	result = NULL;
	while (stack[i])
	{
		nbr = ft_atoi(stack[i]);
		lstadd_back(&result, lstnew(nbr));
		i++;
	}
	return (result);
}

void	print_list(k_list *stack)
{
	while (stack)
	{
		printf("%d ", stack->content);
		stack = stack->next;
	}
	printf("\n");
}

int calculate_move_extract(k_list *stack, int nbr)
{
	k_list *head;
	int position;
	int size;

	head = stack;
	position = 0;
	size = 0;

	while (head)
	{
		size++;
		head = head->next;
	}
	head = stack;
	while (head && nbr != head->content)
	{
		position++;
		head = head->next;
	}
	if ((size - position) < position)
		return (size - position);
	return position;
}

int find_first_smallest(k_list *stack, int nbr)
{
	int next_smallest;

	next_smallest = nbr;
	while (stack)
	{
		if (stack->content < nbr)
		{
			next_smallest = stack->content;
			break;
		}
		stack = stack->next;
	}
	return next_smallest;
}

int find_biggest(k_list *stack, int nbr)
{
	int biggest;

	biggest = nbr;
	while (stack)
	{
		if (stack->content > nbr && stack->content > biggest)
		{
			biggest = stack->content;
			break;
		}
		stack = stack->next;
	}
	return biggest;
}

int find_next_smallest(k_list *stack, int smallest, int nbr)
{
	while (stack)
	{
		if (stack->content < nbr && stack->content > smallest)
			smallest = stack->content;
		stack = stack->next;
	}
	return smallest;
}

void calculate_move_insert(k_list *stack, int nbr)
{
	k_list *head;
	int smallest;
	int biggest;

	head = stack;
	smallest = find_first_smallest(stack, nbr);
	biggest = find_biggest(stack, nbr);

	printf("NEXT SMALL=%d\n", smallest);

	if (smallest != nbr)
	{
		smallest = find_next_smallest(stack, smallest, nbr);
		printf("BIGGEST SMALL=%d\n", smallest);
	}
	else
	{
		printf("BIGGEST=%d\n", biggest);
	}
	
	

	// head = stack;
	// while (head)
	// {
	// 	if (head->content < nbr && head->content > next_smallest)
	// 		next_smallest = head->content;
	// 	size++;
	// 	head = head->next;
	// }
	// head = stack;
	// while (head && head->content != next_smallest)
	// {
	// 	position++;
	// 	head = head->next;
	// }
	// if ((size - position) < position)
	// 	return (size - position);
	// return position; 
}

// void calculate_move_total(k_list *stack_a, k_list *stack_b)
// {
// 	k_list *head = stack_a;
// 	int insert = 0;
// 	int extract = 0;
// 	int total;
// 	int best;
// 	int best_int;

// 	best = 10000;
// 	while (stack_a)
// 	{
// 		extract = calculate_move_extract(head, stack_a->content);
// 		insert = calculate_move_insert(stack_b, stack_a->content);
// 		total = extract + insert;
// 		if (total < best)
// 		{
// 			best = total;
// 			best_int = stack_a->content;
// 		}
// 		printf("%d extract=%d insert=%d\n", stack_a->content, extract, insert);
// 		stack_a = stack_a->next;
// 	}
// 	printf("BEST=%d\n", best_int);
// }

int	main(void)
{
	char	*stack_a_str;
	char	*stack_b_str;
	char	**stack_a;
	char	**stack_b;
	k_list	*stack_a_list;
	k_list	*stack_b_list;
	int action_count;

	action_count = 0;
	stack_a_str = "5 4 2 3 1";
	stack_b_str = "6 4 5";
	stack_a = ft_split(stack_a_str, ' ');
	stack_b = ft_split(stack_b_str, ' ');
	stack_a_list = get_stack(stack_a);
	stack_b_list = get_stack(stack_b);
	// stack_b_list = NULL;



	// ra(&stack_a_list, stack_a_list, &action_count);
	// pb(&stack_a_list, &stack_b_list, &action_count);
	// rra(&stack_a_list, stack_a_list, &action_count);
	// rb(&stack_b_list, stack_b_list, &action_count);
	// sa(stack_a_list, &action_count); // swap a1 a2

	// pa(&stack_a_list, &stack_b_list, &action_count);


	// printf("extract=%d\n",calculate_move_extract(stack_a_list, 54));
	// printf("insert=%d\n",calculate_move_insert(stack_b_list, 54));
	calculate_move_insert(stack_b_list, 3);
	// calculate_move_total(stack_a_list, stack_b_list);

	// printf("%d\n", test);
	// sa(stack_a_list); // swap a1 a2
	// sb(stack_b_list); // swap b1 b2
	// ss(stack_a_list, stack_b_list); // sa sb
	// pa(&stack_a_list, &stack_b_list);
	// pb(&stack_a_list, &stack_b_list);
	// ra(&stack_a_list, stack_a_list);
	// rb(&stack_b_list, stack_b_list);
	// rr(&stack_a_list, &stack_b_list);
	// rra(&stack_a_list, stack_a_list);
	// rrb(&stack_b_list, stack_b_list);
	// rrr(&stack_a_list, stack_a_list, &stack_b_list, stack_b_list);

	// printf("COUNT=%d\n", action_count);
	print_list(stack_a_list);
	print_list(stack_b_list);
	clear_list(&stack_a_list, stack_a);
	clear_list(&stack_b_list, stack_b);
}