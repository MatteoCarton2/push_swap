/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:17:19 by mcarton           #+#    #+#             */
/*   Updated: 2025/02/12 22:01:25 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stddef.h>
# include <stdio.h>

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*previous;
}					t_stack;

// fonctions pour avoir des args valide
int					is_valid_args(char *str);
int					has_duplicates(int argc, char **argv);
char				**check_arguments(int argc, char **argv, size_t *new_argc);

// fonctions pour la gestion de la stack a
void				print_stack(t_stack *stack, char a_or_b);
t_stack				*initialize_stack(int argc, char **argv);
void				free_stack(t_stack *stack);
t_stack				*add_to_stack(t_stack *first, long nbr);

// fonctions pour les manipulations de la stack a et b
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

// fonctions de l'algo
void				algorithm(t_stack **stack_a, t_stack **stack_b);
int					is_sorted(t_stack **stack_a);
int					stack_size(t_stack *stack);
void				sort_three(t_stack **stack);
void				sort_four_or_five(t_stack **stack_a, t_stack **stack_b);

// fonctions utilitaires pour l'algo

int					get_min_position(t_stack *stack);
void				move_to_top(t_stack **stack, int position);
void				push_smallest_to_b(t_stack **stack_a, t_stack **stack_b);

#endif