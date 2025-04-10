/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 04:31:06 by mcarton           #+#    #+#             */
/*   Updated: 2025/04/08 17:42:54 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void find_min_max(t_stack *stack, t_stack **min, t_stack **max)
{
    t_stack *current;
    
    if (!stack)
    {
        *min = NULL;
        *max = NULL;
        return;
    }
    
    *min = stack;
    *max = stack;
    current = stack->next;
    
    while (current)
    {
        if (current->nbr < (*min)->nbr)
            *min = current;
        if (current->nbr > (*max)->nbr)
            *max = current;
        current = current->next;
    }
}
