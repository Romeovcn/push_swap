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

int calculate_move_insert(k_list *stack, int nbr)
{
	k_list *head;
	int next_smallest;
	int position;
	int size;

	head = stack;
	next_smallest = 0;
	position = 0;
	size = 0;

	while (head)
	{
		if (head->content < nbr)
		{
			next_smallest = head->content;
			break;
		}
		head = head->next;
	}
	head = stack;
	while (head)
	{
		if (head->content < nbr && head->content > next_smallest)
			next_smallest = head->content;
		size++;
		head = head->next;
	}
	head = stack;
	while (head && head->content != next_smallest)
	{
		position++;
		head = head->next;
	}
	if ((size - position) < position)
		return (size - position);
	return position; 
}

void calculate_move_total(k_list *stack_a, k_list *stack_b)
{
	k_list *head = stack_a;
	int insert = 0;
	int extract = 0;
	int total;
	int best;
	int best_int;

	best = 10000;
	while (stack_a)
	{
		extract = calculate_move_extract(head, stack_a->content);
		insert = calculate_move_insert(stack_b, stack_a->content);
		total = extract + insert;
		if (total < best)
		{
			best = total;
			best_int = stack_a->content;
		}
		printf("%d extract=%d insert=%d\n", stack_a->content, extract, insert);
		stack_a = stack_a->next;
	}
	printf("BEST=%d\n", best_int);
}

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
	stack_a_str = "9 3 8 10 54 -5";
	stack_b_str = "30 29 28 27 26 -1 -2 -3 -4 -6 -7";
	stack_a = ft_split(stack_a_str, ' ');
	stack_b = ft_split(stack_b_str, ' ');
	stack_a_list = get_stack(stack_a);
	stack_b_list = get_stack(stack_b);
	// stack_b_list = NULL;

	// pb(&stack_a_list, &stack_b_list);
	// pb(&stack_a_list, &stack_b_list);

	// int test = calculate_move_insert(stack_b_list, 9);
	// printf("insert = %d\n", test);
	// if (test > 0)
	// 	while (test--)
	// 		rb(&stack_b_list, stack_b_list);
	// else if (test < 0)
	// 	while (test++)
	// 		rrb(&stack_b_list, stack_b_list);
	// pb(&stack_a_list, &stack_b_list);

	// printf("extract=%d\n",calculate_move_extract(stack_a_list, 54));
	// printf("insert=%d\n",calculate_move_insert(stack_b_list, 54));
	calculate_move_total(stack_a_list, stack_b_list);

	// printf("%d\n", test);
	// sa(stack_a_list); // swap a1 a2
	// sb(stack_b_list); // swap b1 b2
	// ss(stack_a_list, stack_b_list); // sa sb
	// pa(&stack_a_list, &stack_b_list);
	// pb(&stack_a_list, &stack_b_list);
	// ra(&stack_a_list, stack_a_list);
	// rb(&stack_b_list, stack_b_list);
	// rr(&stack_a_list, stack_a_list, &stack_b_list, stack_b_list);
	// rra(&stack_a_list, stack_a_list);
	// rrb(&stack_b_list, stack_b_list);
	// rrr(&stack_a_list, stack_a_list, &stack_b_list, stack_b_list);
	print_list(stack_a_list);
	print_list(stack_b_list);
	clear_list(&stack_a_list, stack_a);
	clear_list(&stack_b_list, stack_b);
}

// 1 5 2 4 3

// / / / / /

// add 1 to b

// 5 2 4 3 /

// 1 / / / /

// push A

// 2 4 3 5 /

// 1 / / /

// push b

// 4 3 5 /

// 2 1 / / /