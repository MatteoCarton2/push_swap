/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:54:00 by mcarton           #+#    #+#             */
/*   Updated: 2025/04/10 15:08:38 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && (*stack_a)->next)
		rra(stack_a, 0);
	if (*stack_b && (*stack_b)->next)
		rrb(stack_b, 0);
	write(1, "rrr\n", 4);
}
