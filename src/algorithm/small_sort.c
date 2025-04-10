/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:14:21 by mcarton           #+#    #+#             */
/*   Updated: 2025/04/10 18:07:27 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push_smallest_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	position;

	position = get_min_position(*stack_a);
	move_to_top(stack_a, position);
	pb(stack_a, stack_b);
}

static void	find_min_max(t_stack *stack, t_stack **min, t_stack **max)
{
	t_stack	*current;

	if (!stack)
	{
		*min = NULL;
		*max = NULL;
		return ;
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

void	sort_three(t_stack **stack_a)
{
	t_stack	*biggest_node;
	t_stack	*min_node;

	find_min_max(*stack_a, &min_node, &biggest_node);
	if (biggest_node == *stack_a)
		ra(stack_a, 1);
	else if ((*stack_a)->next == biggest_node)
		rra(stack_a, 1);
	if ((*stack_a)->nbr > (*stack_a)->next->nbr)
		sa(stack_a, 1);
}

void	sort_four_or_five(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size == 4)
	{
		push_smallest_to_b(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
	}
	else if (size == 5)
	{
		push_smallest_to_b(stack_a, stack_b);
		push_smallest_to_b(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}

void	move_to_top(t_stack **stack, int position)
{
	int	size;

	size = stack_size(*stack);
	if (position <= size / 2)
	{
		while (position--)
			ra(stack, 1);
	}
	else
	{
		position = size - position;
		while (position--)
			rra(stack, 1);
	}
}
