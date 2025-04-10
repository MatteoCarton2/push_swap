/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:59:00 by mcarton           #+#    #+#             */
/*   Updated: 2025/04/10 19:24:34 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	find_direction(t_stack *stack, int target_order, int size)
{
	int		position;
	t_stack	*current;

	if (!stack)
		return (0);
	current = stack;
	position = 0;
	while (current && current->order != target_order)
	{
		position++;
		current = current->next;
	}
	if (!current)
		return (0);
	if (position <= size / 2)
		return (1);
	else
		return (-1);
}

static void	move_max_to_top(t_stack **stack_a, t_stack **stack_b, int original_size)
{
	int	max_order;
	int	direction;
	int	size;
	
	max_order = original_size;
	size = stack_size(*stack_b);
	direction = find_direction(*stack_b, max_order, size);
	while (*stack_b && (*stack_b)->order != max_order)
	{
		if ((*stack_b)->order == max_order - 1)
		{
			pa(stack_a, stack_b);
		}
		else if (direction == 1)
		{
			rb(stack_b, 1);
		}
		else
		{
			rrb(stack_b, 1);
		}
	}
}

void	big_sort_part2(t_stack **stack_a, t_stack **stack_b)
{
	int size;

	if (!stack_a || !stack_b)
		return ;
	size = stack_size(*stack_b);
	while (*stack_b)
	{
		move_max_to_top(stack_a, stack_b, size);
		pa(stack_a, stack_b);
		if (*stack_a && (*stack_a)->next
			&& (*stack_a)->order > (*stack_a)->next->order)
		{
			sa(stack_a, 1);
		}
	}
}
