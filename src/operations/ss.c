/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:24:54 by mcarton           #+#    #+#             */
/*   Updated: 2025/02/12 12:11:03 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void ss(t_stack **stack_a, t_stack **stack_b) // A CHANGER, PAS ENCORE COMPLET
{
    if (*stack_a && (*stack_a)->next)
        sa(stack_a, 0);
    if (*stack_b && (*stack_b)->next)
        sb(stack_b, 0);
}