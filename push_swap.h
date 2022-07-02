#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_move
{
	int					nbr;

	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;

	int 				total;
}						t_move;

typedef struct stack_list
{
	int					content;
	struct stack_list	*next;
}						k_list;

void					sa(k_list *stack_a);
void					pa(k_list **stack_a, k_list **stack_b);
void					pb(k_list **stack_a, k_list **stack_b);
void					ra(k_list **stack_a_ptr, k_list *stack_a);
void					rb(k_list **stack_b_ptr, k_list *stack_b);
void					rr(k_list **stack_a_ptr, k_list **stack_b_ptr);
void					rra(k_list **stack_a_ptr, k_list *stack_a);
void					rrb(k_list **stack_b_ptr, k_list *stack_b);
void					rrr(k_list **stack_a_ptr, k_list **stack_b_ptr);

k_list					*get_stack(char *stack_str);
void					clear_list(k_list **stack_list);
int						get_stack_size(k_list *stack);

k_list					*lstlast(k_list *lst);
void					lstadd_back(k_list **lst, k_list *new);
k_list					*lstnew(int content);
void					print_list(k_list *stack);

t_move calculate_move_total2(k_list *stack_a, k_list *stack_b, int biggest, int second_biggest, int third_biggest);
int						calculate_move_extract(k_list *stack, int nbr, t_move *current);
int						find_first_smallest(k_list *stack, int nbr);
int						find_biggest(k_list *stack, int nbr);
int						find_next_smallest(k_list *stack, int smallest,
							int nbr);
int						get_move(k_list *stack, int nbr, t_move *current);
int						check_is_reverse_better(k_list *stack, int nbr);
int						calculate_move_insert(k_list *stack, int nbr, t_move *current);
t_move						calculate_move_total(k_list *stack_a, k_list *stack_b,
							int biggest, int second_biggest, int third_biggest);


#endif