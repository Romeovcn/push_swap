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