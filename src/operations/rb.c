/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:24:16 by mcarton           #+#    #+#             */
/*   Updated: 2025/02/12 11:30:59 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    rb(t_stack **stack_b)
{
    t_stack *tmp;
    t_stack *last;
    if (!(*stack_b) || !(*stack_b)->next)
        return;
    tmp = *stack_b;
    last = *stack_b;
    *stack_b = (*stack_b)->next;
    (*stack_b)->previous = NULL;
    while (last->next != NULL)
        last = last->next;
    last->next = tmp;
    tmp->previous = last;
    tmp->next = NULL;
    write (1, "rb\n", 3);
}