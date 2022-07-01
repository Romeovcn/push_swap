#include "push_swap.h"

int calculate_move_extract(k_list *stack, int nbr, t_move *current)
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
	{
		current->rra = (size - position); 
		return (size - position);
	}
	current->ra = position; 
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

int get_move(k_list *stack, int nbr, t_move *current)
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
	{
		current->rrb = (size - position);
		return (size - position);
	}
		current->rb = position;
	return position; 
}

int calculate_move_insert(k_list *stack, int nbr, t_move *current)
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
		move = get_move(stack, smallest, current);
		// printf("BIGGEST SMALL=%d\n", smallest);
	}
	else
	{
		move = get_move(stack, biggest, current);
		// printf("BIGGEST=%d\n", biggest);
	}
	// printf("POS=%d\n", move);
	// printf("REVERSE=%d\n", check_is_reverse_better(stack, smallest));
	return move;
}

void init_struct(t_move *current)
{
	current->rra = 0;
	current->ra = 0;
	current->rrr = 0;
	current->rr = 0;
	current->rrb = 0;
	current->rb = 0;
	current->total = 0;
}

int get_total_move(t_move *current)
{
	int total;

	total = current->rra + current->ra + current->rrr + current->rr + current->rrb + current->rb;
	current->total = total;
	return total;
}

void rrr_check(t_move *current)
{
	while (current->ra >= 1 && current->rb >= 1)
	{
		current->ra--;
		current->rb--;
		current->rr++;
	}
	while (current->rra >= 1 && current->rrb >= 1)
	{
		current->rra--;
		current->rrb--;
		current->rrr++;
	}
}

t_move calculate_move_total(k_list *stack_a, k_list *stack_b, int biggest, int second_biggest)
{
	k_list *head = stack_a;
	int insert = 0;
	int extract = 0;
	t_move current;
	t_move best;

	init_struct(&best);
	best.rra = 1000;
	while (stack_a)
	{
		init_struct(&current);
		current.nbr = stack_a->content;
		extract = calculate_move_extract(head, stack_a->content, &current);
		insert = calculate_move_insert(stack_b, stack_a->content, &current);
		rrr_check(&current);
		if (get_total_move(&current) < get_total_move(&best) && stack_a->content != biggest && stack_a->content != second_biggest)
			best = current;
		// printf("%d extract=%d insert=%d\n", stack_a->content, extract, insert);
		stack_a = stack_a->next;
		// printf("NBR=%d RRA=%d RA=%d RR=%d RRB=%d RB=%d RRR=%d TOTAL=%d\n\n", current.nbr, current.rra, current.ra, current.rr, current.rrb, current.rb, current.rrr, current.total);
	}
	// printf("BEST=%d extract=%d insert=%d TOTAL=%d\n", best.nbr, extract, insert, best.total);
	// printf("BEST=%d\n", best.nbr);
	return best;
}