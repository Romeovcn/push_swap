#include "push_swap.h"
#include "libft/libft.h"

void sa(k_list *stack_a)
{
	int tmp;

	if (!stack_a->content || !stack_a->next->content)
		return ;
	tmp = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = tmp;
}

void sb(k_list *stack_b)
{
	int tmp;

	if (!stack_b->content || !stack_b->next->content)
		return ;
	tmp = stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->next->content = tmp;
}

void ss(k_list *stack_a, k_list *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

// k_list	*lst_new(int content)
// {
// 	k_list	*result;

// 	result = malloc(sizeof(k_list));
// 	if (!result)
// 		return (0);
// 	result->content = content;
// 	result->next = NULL;
// 	return (result);
// }

// void	lstadd_back(k_list **lst, k_list *new)
// {
// 	k_list	*last;

// 	if (*lst)
// 	{
// 		last = ft_lstlast(*lst);
// 		last->next = new;
// 	}
// 	else
// 		*lst = new;
// }

k_list	*get_stack(char **stack)
{
	k_list *result;
	int i;
	int	nbr;

	i = 0;
	result = NULL;
	while (stack[i])
	{
		nbr = ft_atoi(stack[i]);
		lstadd_back(&result, lstnew(nbr));
		i++;
	}
	return result;
}


// void	sort(int *stack_a, int *stack_b)
// {
// 	int top;
// 	int bottom;
// 	int pivot;
// 	int stack_b_index = 0;
// 	top = 0;
// 	bottom = 0;
// 	while (stack_a[bottom])
// 		bottom++;
// 	bottom--;
// 	pivot = bottom / 2 - 1;
// 	while (stack_a[top] < stack_a[pivot])
// 		top++;
// 	while (stack_a[bottom] > stack_a[pivot])
// 		bottom--;
// 	// if (top == bottom)
// 	// 	exit (0);
// 	printf("pivot id = %d pivot = %d\n", pivot, stack_a[pivot]);
// 	printf("top id = %d top = %d\n", top, stack_a[top]);
// 	printf("bottom id = %d bottom = %d\n", bottom, stack_a[bottom]);
// }

int main()
{
	char *stack_a_str = "1 56 57 43 29";
	char **stack_a = ft_split(stack_a_str, ' ');

	k_list *stack_a_list = get_stack(stack_a);
	sa(stack_a_list);
	while (stack_a_list)
	{
		printf("%d   ", stack_a_list->content);
		stack_a_list = stack_a_list->next;
	}
}