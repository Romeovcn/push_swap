#include "push_swap.h"

k_list	*lstlast(k_list *lst)
{
	k_list	*head;

	if (lst == NULL)
		return (0);
	head = lst;
	while (head->next)
		head = head->next;
	return (head);
}

void	lstadd_back(k_list **lst, k_list *new)
{
	k_list	*last;

	if (*lst)
	{
		last = lstlast(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

k_list	*lstnew(int content)
{
	k_list	*result;

	result = malloc(sizeof(k_list));
	if (!result)
		return (0);
	result->content = content;
	result->next = NULL;
	return (result);
}

int	check_digit_error(char *nbr)
{
	while(*nbr)
	{
		if (*nbr < '0' || *nbr > '9')
			return 1;
		nbr++;
	}
	return 0;
}

k_list *get_2_args_stack(char *stack_str)
{
	char **stack_array;
	k_list	*result;
	int		i;
	int		nbr;

	stack_array = ft_split(stack_str, ' ');
	i = 0;
	result = NULL;
	while (stack_array[i])
	{
		nbr = ft_atoi(stack_array[i]);
		printf("NBR=%d ERROR=%d\n", nbr, check_digit_error(stack_array[i]));
		lstadd_back(&result, lstnew(nbr));
		i++;
	}
	i = 0;
	while (stack_array[i])
		free(stack_array[i++]);
	free(stack_array);
	return result;
}


k_list *get_multiple_args_stack(char **argv)
{
	k_list	*result;
	int		i;
	int		nbr;

	i = 1;
	result = NULL;
	while (argv[i])
	{
		nbr = ft_atoi(argv[i]);
		printf("NBR=%d ERROR=%d\n", nbr, check_digit_error(argv[i]));
		lstadd_back(&result, lstnew(nbr));
		i++;
	}
	return result;
}


k_list	*get_stack(int argc, char **argv)
{
	k_list	*result;

	if (argc == 2)
		result = get_2_args_stack(argv[1]);
	else
		result = get_multiple_args_stack(argv);

	return (result);
}