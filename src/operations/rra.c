/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:01:38 by mcarton           #+#    #+#             */
/*   Updated: 2025/02/14 11:29:19 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* Décale d’une position vers le bas tous les élements de
la pile a. Le dernier élément devient le premier. */
void rra(t_stack **stack_a, int write_or_not)
{
    t_stack *last;
    t_stack *second_last;

    if (!(*stack_a) || !(*stack_a)->next)
        return;
    last = *stack_a;
    while (last->next != NULL)
        last = last->next;
    second_last = last->previous;
    second_last->next = NULL;
    last->next = *stack_a;
    last->previous = NULL;
    (*stack_a)->previous = last;
    *stack_a = last;
    update_index(*stack_a);
    if (write_or_not == 1)
        write (1, "rra\n", 4);
}