#include "push_swap.h"

void	print_list(k_list *stack)
{
	while (stack)
	{
		ft_printf("%d ", stack->content);
		stack = stack->next;
	}
	ft_printf("\n");
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
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	get_biggest(k_list *stack)
{
	int	biggest;

	biggest = -2147483648;
	while (stack)
	{
		if (stack->content > biggest)
			biggest = stack->content;
		stack = stack->next;
	}
	return (biggest);
}

int	get_next_biggest(k_list *stack, int biggest)
{
	int	second_biggest;

	second_biggest = -2147483648;
	while (stack)
	{
		if (stack->content < biggest && stack->content > second_biggest)
			second_biggest = stack->content;
		stack = stack->next;
	}
	return (second_biggest);
}

int	get_smallest(k_list *stack)
{
	int	smallest;

	smallest = 2147483647;
	while (stack)
	{
		if (stack->content < smallest)
			smallest = stack->content;
		stack = stack->next;
	}
	return (smallest);
}

void	get_data(k_list *stack_a, t_data *data)
{
	data->size = get_stack_size(stack_a);
	data->smallest = get_smallest(stack_a);
	data->biggest = get_biggest(stack_a);
	data->second_biggest = get_next_biggest(stack_a, data->biggest);
}

int	check_is_reverse_better(k_list *stack, int nbr)
{
	int	position;
	int	size;

	position = 0;
	size = get_stack_size(stack);
	while (stack && stack->content != nbr)
	{
		position++;
		stack = stack->next;
	}
	if ((size - position) < position)
		return (1);
	return (0);
}

void	tester(k_list *stack_a)
{
	int	previous;
	int	i;

	previous = -2147483648;
	i = 0;
	while (stack_a)
	{
		if (stack_a->content < previous)
			printf("%d IS BIGGER THAN %d ERROR\n", previous, stack_a->content);
		i++;
		previous = stack_a->content;
		stack_a = stack_a->next;
	}
	printf("SIZE=%d\n", i);
}
