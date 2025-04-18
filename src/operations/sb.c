/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:04:55 by mcarton           #+#    #+#             */
/*   Updated: 2025/04/10 16:12:34 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sb(t_stack **stack_b, int write_or_not)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	if (first->next)
		first->next->previous = first;
	first->previous = second;
	second->next = first;
	second->previous = NULL;
	*stack_b = second;
	if (write_or_not == 1)
		write(1, "sb\n", 3);
}
