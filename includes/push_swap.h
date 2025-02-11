/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:17:19 by mcarton           #+#    #+#             */
/*   Updated: 2025/02/11 16:21:26 by mcarton          ###   ########.fr       */
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
void				print_stack(t_stack *stack);
t_stack				*initialize_stack(int argc, char **argv);
void				free_stack(t_stack *stack);
t_stack				*add_to_stack(t_stack *first, long nbr);

// fonctions pour les manipulations de la stack a et b
void				sa(t_stack **stack_a);

#endif