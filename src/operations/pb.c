/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:00:31 by mcarton           #+#    #+#             */
/*   Updated: 2025/02/11 21:23:39 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void pb(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;

    if (!(*stack_a))
        return;

    tmp = *stack_a; // Stocke le top de stock a dans tmp
    *stack_a = (*stack_a)->next; // Avance stack_a au 2eme élément

    if (*stack_a) // Si il y'a qqc au 2eme, ça veux dire qu'il faut faire pointer le previous de ce 2eme vers NULL
        (*stack_a)->previous = NULL;

    tmp->next = *stack_b; // Placer tmp au début de stack_b
    if (*stack_b) // même chose qu'au dessus pour la stack a
        (*stack_b)->previous = tmp;

    *stack_b = tmp; // Met à jour stack_b avec tmp comme nouveau top

    write(1, "pb\n", 3);
}
