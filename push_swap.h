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

	int					total;
}						t_move;

typedef struct stack_list
{
	int					content;
	struct stack_list	*next;
}						k_list;

typedef struct s_data
{
	int					size;

	int					smallest;
	int					biggest;
	int					second_biggest;
	int					third_biggest;

	k_list				*sorted_int;
}						t_data;

void					sa(k_list *stack_a);
void					pa(k_list **stack_a, k_list **stack_b);
void					pb(k_list **stack_a, k_list **stack_b);
void					ra(k_list **stack_a_ptr, k_list *stack_a);
void					rb(k_list **stack_b_ptr, k_list *stack_b);
void					rr(k_list **stack_a_ptr, k_list **stack_b_ptr);
void					rra(k_list **stack_a_ptr, k_list *stack_a);
void					rrb(k_list **stack_b_ptr, k_list *stack_b);
void					rrr(k_list **stack_a_ptr, k_list **stack_b_ptr);

k_list					*get_stack(int argc, char **argv);
void					clear_list(k_list **stack_list);
int						get_stack_size(k_list *stack);

// Utils

k_list					*lstlast(k_list *lst);
void					lstadd_back(k_list **lst, k_list *new);
k_list					*lstnew(int content);
void					print_list(k_list *stack);
int						get_smallest(k_list *stack);
int						get_biggest(k_list *stack);
int						get_next_biggest(k_list *stack, int biggest);
void					get_data(k_list *stack_a, t_data *data);
int						check_is_reverse_better(k_list *stack, int nbr);
void					tester(k_list *stack_a);

int						calculate_move_extract(k_list *stack, int nbr,
							t_move *current);
int						find_first_smallest(k_list *stack, int nbr);
int						find_biggest(k_list *stack, int nbr);
int						find_next_smallest(k_list *stack, int smallest,
							int nbr);
int						get_move(k_list *stack, int nbr, t_move *current);
int						check_is_reverse_better(k_list *stack, int nbr);
int						calculate_move_insert(k_list *stack, int nbr,
							t_move *current);
t_move					calculate_move_total(k_list *stack_a, k_list *stack_b,
							t_data data);

void					init_struct(t_move *current);

int						get_first_bigger(k_list *stack, int nbr);
int						get_next_bigger(k_list *stack, int nbr);
int						get_move_stack_a(k_list *stack, int nbr,
							t_move *current);
t_move					calculate_insert_stack_a(int nbr, k_list *stack);

void					do_op(k_list **stack_a, k_list **stack_b, t_move best);
void					do_op_2(k_list **stack_a, k_list **stack_b,
							t_move best);

// Sort big stack

void					sort_first_half(k_list **stack_a, k_list **stack_b,
							t_data *data, t_move *best);
void					sort_second_half(k_list **stack_a, k_list **stack_b,
							t_data *data, t_move *best);
void					put_second_half_back(k_list **stack_a, k_list **stack_b,
							t_data *data, t_move *best);

// Sort small stack

void					sort_in_stack_b(k_list **stack_a, k_list **stack_b,
							t_data *data, t_move *best);
void					push_back_stack_a(k_list **stack_a, k_list **stack_b,
							t_data *data, t_move *best);

// Check error

int						check_duplicate(k_list *stack, long nbr);
int						check_digit_error(char *nbr);
void					check_error(k_list *stack, long nbr, char *argv);

#endif