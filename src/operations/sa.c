/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:04:40 by mcarton           #+#    #+#             */
/*   Updated: 2025/04/10 15:09:02 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_stack **stack_a, int write_or_not)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	if (first->next)
		first->next->previous = first;
	first->previous = second;
	second->next = first;
	second->previous = NULL;
	*stack_a = second;
	update_index(*stack_a);
	if (write_or_not == 1)
		write(1, "sa\n", 3);
}
