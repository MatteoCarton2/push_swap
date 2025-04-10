/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:00:31 by mcarton           #+#    #+#             */
/*   Updated: 2025/04/10 14:55:41 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!(*stack_a))
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->previous = NULL;
	tmp->next = *stack_b;
	if (*stack_b)
		(*stack_b)->previous = tmp;
	tmp->previous = NULL;
	*stack_b = tmp;
	update_index(*stack_a);
	update_index(*stack_b);
	write(1, "pb\n", 3);
}
