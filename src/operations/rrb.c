/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:43:45 by mcarton           #+#    #+#             */
/*   Updated: 2025/02/12 14:49:08 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rrb(t_stack **stack_b, int write_or_not)
{
	t_stack *last;
	t_stack *second_last;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	last = *stack_b;
	while (last->next != NULL)
		last = last->next;
	second_last = last->previous;
	(*stack_b)->previous = last;
	last->next = *stack_b;
	last->previous = NULL;
	second_last->next = NULL;
	*stack_b = last;
	if (write_or_not == 1)
		write(1, "rrb\n", 4);
}