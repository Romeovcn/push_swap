#include "push_swap.h"

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
			biggest = stack->content;
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

int get_move(k_list *stack, int nbr)
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
		return (size - position);
	return position; 
}

int calculate_move_insert(k_list *stack, int nbr)
{
	k_list *head;
	int smallest;
	int biggest;
	int move;

	head = stack;
	smallest = find_first_smallest(stack, nbr);
	biggest = find_biggest(stack, nbr);

	// printf("FIRST SMALL=%d\n", smallest);

	if (smallest != nbr)
	{
		smallest = find_next_smallest(stack, smallest, nbr);
		move = get_move(stack, smallest);
		// printf("BIGGEST SMALL=%d\n", smallest);
	}
	else
	{
		move = get_move(stack, biggest);
		// printf("BIGGEST=%d\n", biggest);
	}
	// printf("POS=%d\n", move);
	// printf("REVERSE=%d\n", check_is_reverse_better(stack, smallest));
	return move;
}

int calculate_move_total(k_list *stack_a, k_list *stack_b, int biggest, int second_biggest)
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
		if (total < best && stack_a->content != biggest && stack_a->content != second_biggest)
		{
			best = total;
			best_int = stack_a->content;
		}
		printf("%d extract=%d insert=%d total=%d\n", stack_a->content, extract, insert, total);
		stack_a = stack_a->next;
	}
	printf("BEST=%d\n", best_int);
	return best_int;
}