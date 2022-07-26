/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:29:09 by rvincent          #+#    #+#             */
/*   Updated: 2022/07/26 18:39:56 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}						t_stack;

typedef struct s_data
{
	int					size;

	int					smallest;
	int					biggest;
	int					second_biggest;
	int					third_biggest;

	t_stack				*sorted_int;
}						t_data;

void					sa(t_stack *stack_a);
void					sb(t_stack *stack_b);
void					ss(t_stack *stack_a, t_stack *stack_b);
void					pa(t_stack **stack_a, t_stack **stack_b);
void					pb(t_stack **stack_a, t_stack **stack_b);
void					ra(t_stack **stack_a);
void					rb(t_stack **stack_b_ptr);
void					rr(t_stack **stack_a_ptr, t_stack **stack_b_ptr);
void					rra(t_stack **stack_a);
void					rrb(t_stack **stack_b_ptr);
void					rrr(t_stack **stack_a_ptr, t_stack **stack_b_ptr);

// Get stack
t_stack					*get_stack(int argc, char **argv);
void					clear_list(t_stack **stact_stack);
int						get_stack_size(t_stack *stack);

// Get best big stack
void					init_struct(t_move *current, int nbr);
void					reverse_check(t_move *current);
int						check_int_already_sorted(int nbr, t_stack *sorted_int);
int						get_total_move(t_move *current);

// Utils
t_stack					*lstlast(t_stack *lst);
void					lstadd_back(t_stack **lst, t_stack *new);
t_stack					*lstnew(int content);
void					print_list(t_stack *stack);
int						get_smallest(t_stack *stack);
int						get_biggest(t_stack *stack);
int						get_next_biggest(t_stack *stack, int biggest);
void					get_data(t_stack *stack_a, t_data *data);
int						check_is_reverse_better(t_stack *stack, int nbr);
int						is_sorted(t_stack *stack_a);
void					push_stack_b_to_stack_a(t_stack **stack_a,
							t_stack **stack_b);

int						calculate_move_extract(t_stack *stack, int nbr,
							t_move *current);
int						find_first_smallest(t_stack *stack, int nbr);
int						find_biggest(t_stack *stack, int nbr);
int						find_next_smallest(t_stack *stack, int smallest,
							int nbr);
int						get_move(t_stack *stack, int nbr, t_move *current);
int						check_is_reverse_better(t_stack *stack, int nbr);
int						calculate_move_insert(t_stack *stack, int nbr,
							t_move *current);
t_move					calculate_move_total(t_stack *stack_a, t_stack *stack_b,
							t_data data);

int						get_first_bigger(t_stack *stack, int nbr);
int						get_next_bigger(t_stack *stack, int nbr);
t_move					calculate_insert_stack_a(int nbr, t_stack *stack);

void					do_op(t_stack **stack_a, t_stack **stack_b,
							t_move best);
void					do_op_2(t_stack **stack_a, t_stack **stack_b,
							t_move best);

// Sort big stack
void					sort_first_half(t_stack **stack_a, t_stack **stack_b,
							t_data *data, t_move *best);
void					sort_second_half(t_stack **stack_a, t_stack **stack_b,
							t_data *data, t_move *best);
void					put_second_half_back(t_stack **stack_a,
							t_stack **stack_b, t_data *data, t_move *best);
void					sort_big_stack(t_stack **stack_a, t_stack **stack_b,
							t_data *data, t_move *best);

// Sort medium stack
void					sort_in_stack_b(t_stack **stack_a, t_stack **stack_b,
							t_data *data, t_move *best);
void					push_back_stack_a(t_stack **stack_a, t_stack **stack_b);
void					sort_medium_stack(t_stack **stack_a, t_stack **stack_b,
							t_data *data, t_move *best);

// Sort small stack
void					sort_small_stack(t_stack **stack_a);

// Check error
int						check_duplicate(t_stack *stack, long nbr);
int						check_digit_error(char *nbr);
void					check_error(t_stack *stack, long nbr, char *argv);

#endif