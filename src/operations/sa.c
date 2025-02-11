/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:04:40 by mcarton           #+#    #+#             */
/*   Updated: 2025/02/11 21:21:47 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void				sa(t_stack **stack_a)
{
    t_stack *first;
    t_stack *second;

    if (!(*stack_a) || !(*stack_a)->next)
        return;
    first = *stack_a;
    second = first->next;

    // 🔄 Echange des pointeurs
    first->next = second->next;
    if (first->next)
        first->next->previous = first; // pour que le 3ème son prévious pointe vers le nouveau 2ème (first)
    first->previous = second;
    second->next = first;
    second->previous = NULL;
    *stack_a = second;

    write(1, "sa\n", 3);
}