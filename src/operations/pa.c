/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:29:47 by mcarton           #+#    #+#             */
/*   Updated: 2025/02/14 11:27:57 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void pa(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;
    
    if (!(*stack_b))
        return;
    tmp = *stack_b;
    *stack_b = (*stack_b)->next;
    if(*stack_b)
        (*stack_b)->previous = NULL;
    tmp->next = *stack_a;
    if (*stack_a)
        (*stack_a)->previous = tmp;
    tmp->previous = NULL;
    *stack_a = tmp;
    update_index(*stack_a);
    update_index(*stack_b);
    write (1, "pa\n", 3);
}