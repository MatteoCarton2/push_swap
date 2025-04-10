/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:17:19 by mcarton           #+#    #+#             */
/*   Updated: 2025/04/10 16:51:33 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stddef.h>

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

typedef struct s_stack
{
	long			nbr;
	int				order;
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
int					get_min_position(t_stack *stack);
int					stack_size(t_stack *stack);

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
void				move_to_top(t_stack **stack, int position);

// big_sort_a.c
void				big_sort(t_stack **stack_a, t_stack **stack_b);
void				big_sort_part1(t_stack **stack_a, t_stack **stack_b,
						int size);
void				assign_orders(t_stack **stack, int size);
void				process_chunk_element(t_stack **stack_a, t_stack **stack_b,
						int *chunk_limit, int chunk_size);

// big_sort_b.c
void				big_sort_part2(t_stack **stack_a, t_stack **stack_b);
void				move_max_to_top(t_stack **stack_a, t_stack **stack_b);

// algo_utils.c
void				find_min_max(t_stack *stack, t_stack **min, t_stack **max);

#endif