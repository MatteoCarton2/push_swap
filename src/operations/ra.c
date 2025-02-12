/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:06:30 by mcarton           #+#    #+#             */
/*   Updated: 2025/02/12 11:19:26 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    ra(t_stack **stack_a)
{
    t_stack *tmp;
    t_stack *last;
    if (!(*stack_a) || !(*stack_a)->next)
        return;
    tmp = *stack_a;
    last = *stack_a;
    *stack_a = (*stack_a)->next; // avance stack_a au 2eme element (qui sera désormais le 1er)
    (*stack_a)->previous = NULL; // comme c'est le nouveau 1er, pas de previous
    while (last->next != NULL) // aller au dernier element
        last = last->next;
    last->next = tmp; // ajouter tmp (qui contient l'ancien 1er element) à la fin
    tmp->previous = last;
    tmp->next = NULL;
    write (1, "ra\n", 3);
}