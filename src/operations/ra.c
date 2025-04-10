/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:06:30 by mcarton           #+#    #+#             */
/*   Updated: 2025/04/10 15:34:58 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_stack **stack_a, int write_or_not)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	last = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->previous = NULL;
	while (last->next != NULL)
		last = last->next;
	last->next = tmp;
	tmp->previous = last;
	tmp->next = NULL;
	if (write_or_not == 1)
		write(1, "ra\n", 3);
}
