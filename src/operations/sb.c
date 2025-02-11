/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:04:55 by mcarton           #+#    #+#             */
/*   Updated: 2025/02/11 21:21:53 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void				sb(t_stack **stack_b)
{
    t_stack *first;
    t_stack *second;

    if (!(*stack_b) || !(*stack_b)->next)
        return;
    first = *stack_b;
    second = first->next;
    
    // 🔄 Echange des pointeurs
    first->next = second->next;
    if (first->next)
        first->next->previous = first; // pour le 3eme
    first->previous = second;
    second->next = first;
    second->previous = NULL;
    *stack_b = second;

    write(1, "sb\n", 3);
}