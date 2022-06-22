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