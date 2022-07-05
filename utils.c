#include "push_swap.h"

void	print_list(k_list *stack)
{
	while (stack)
	{
		printf("%d ", stack->content);
		stack = stack->next;
	}
	printf("\n");
}

void	clear_list(k_list **stack_list)
{
	k_list	*tmp;

	while (*stack_list)
	{
		tmp = (*stack_list)->next;
		free(*stack_list);
		*stack_list = tmp;
	}
}

int	get_stack_size(k_list *stack)
{
	int size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
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
		if (stack->content < biggest && stack->content > second_biggest)
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

void get_data(k_list	*stack_a, t_data *data)
{
	data->size = get_stack_size(stack_a);
	data->smallest = get_smallest(stack_a);
	data->biggest = get_biggest(stack_a);
	data->second_biggest = get_second_biggest(stack_a, data->biggest);
}