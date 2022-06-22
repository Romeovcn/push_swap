#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct stack_list
{
	int			content;
	struct stack_list	*next;
}					k_list;

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

k_list	*lstlast(k_list *lst);
void	lstadd_back(k_list **lst, k_list *new);
k_list	*lstnew(int content);

#endif