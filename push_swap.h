#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct stack_list
{
	int					content;
	struct stack_list	*next;
}						k_list;

void					sa(k_list *stack_a);
void					sb(k_list *stack_b);
void					ss(k_list *stack_a, k_list *stack_b);
void					pa(k_list **stack_a, k_list **stack_b);
void					pb(k_list **stack_a, k_list **stack_b);
void					ra(k_list **stack_a_ptr, k_list *stack_a);
void					rb(k_list **stack_b_ptr, k_list *stack_b);
void					rr(k_list **stack_a_ptr, k_list *stack_a,
							k_list **stack_b_ptr, k_list *stack_b);
void					rra(k_list **stack_a_ptr, k_list *stack_a);
void					rrb(k_list **stack_a_ptr, k_list *stack_a);
void					rrr(k_list **stack_a_ptr, k_list *stack_a,
							k_list **stack_b_ptr, k_list *stack_b);

void					clear_list(k_list **stack_list, char **stack);

k_list					*lstlast(k_list *lst);
void					lstadd_back(k_list **lst, k_list *new);
k_list					*lstnew(int content);

#endif