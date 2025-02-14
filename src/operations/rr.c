/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:32:29 by mcarton           #+#    #+#             */
/*   Updated: 2025/02/14 11:50:15 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    rr(t_stack **stack_a, t_stack **stack_b)
{
    if (*stack_a && (*stack_a)->next)
        ra(stack_a, 0);
    if (*stack_b && (*stack_b)->next)
        rb(stack_b, 0);
    write(1, "rr\n", 3);
}