/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:17:19 by mcarton           #+#    #+#             */
/*   Updated: 2025/02/14 16:24:16 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stddef.h>
# include <stdio.h>

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*previous;
}					t_stack;

// PARSING

	// parsing.c
char				**check_arguments(int argc, char **argv, size_t *new_argc);
int					is_valid_args(char *str);
int					has_duplicates(int argc, char **argv);

// STACK

	// stack_init.c
t_stack				*initialize_stack(int argc, char **argv);
t_stack				*add_to_stack(t_stack *first, long nbr);

	// stack_utils.c
void				free_stack(t_stack *stack);
void				print_stack(t_stack *stack, char a_or_b);
void				update_index(t_stack *stack);
int 				get_min_position(t_stack *stack); // voir si c'est utile ou pas
int 				stack_size(t_stack *stack);

// OPERATIONS

	// operations.c

void				sa(t_stack **stack_a, int write_or_not);
void				sb(t_stack **stack_b, int write_or_not);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a, int write_or_not);
void				rb(t_stack **stack_b, int write_or_not);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a, int write_or_not);
void				rrb(t_stack **stack_b, int write_or_not);
void				rrr(t_stack **stack_a, t_stack **stack_b);

// ALGORITHM

	// algorithm.c
void				algorithm(t_stack **stack_a, t_stack **stack_b);
int					is_sorted(t_stack **stack_a);

	// small_sort.c
void				sort_three(t_stack **stack);
void				sort_four_or_five(t_stack **stack_a, t_stack **stack_b);
void 				push_smallest_to_b(t_stack **stack_a, t_stack **stack_b);
void 				move_to_top(t_stack **stack, int position);

	// big_sort.c
void				big_sort(t_stack **stack_a, t_stack **stack_b);
void				push_initial_elements(t_stack **stack_a, t_stack **stack_b);

#endif