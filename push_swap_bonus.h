/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 22:19:42 by rvincent          #+#    #+#             */
/*   Updated: 2022/07/25 17:57:02 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct stack_list
{
	int					content;
	struct stack_list	*next;
}						t_stack;

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

t_stack					*get_stack(int argc, char **argv);
void					clear_list(t_stack **stact_stack);
int						get_stack_size(t_stack *stack);

int						is_sorted(t_stack *stack_a);
void					clear_list(t_stack **stact_stack);
void					print_list(t_stack *stack);

int						check_duplicate(t_stack *stack, long nbr);
int						check_digit_error(char *nbr);
void					check_error(t_stack *stack, long nbr, char *argv);

#endif