/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:55:49 by mcarton           #+#    #+#             */
/*   Updated: 2025/04/10 19:55:31 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	find_min_without_order(t_stack *stack)
{
	t_stack	*current;
	int		min;

	if (!stack)
		return (0);
	current = stack;
	min = INT_MAX;
	while (current)
	{
		if (current->nbr < min && current->order == -1)
			min = current->nbr;
		current = current->next;
	}
	return (min);
}

static void	assign_orders(t_stack **stack, int size)
{
	t_stack	*current;
	int		min;
	int		order;

	if (!stack)
		return ;
	order = 1;
	while (order <= size)
	{
		min = find_min_without_order(*stack);
		current = *stack;
		while (current)
		{
			if (current->nbr == min)
			{
				current->order = order;
				break ;
			}
			current = current->next;
		}
		order++;
	}
}

/* Processes one element from stack A
If element's order is within current chunk limit, pushes it to stack B
Otherwise, rotates it to the bottom of stack A*/
static void	process_chunk_element(t_stack **stack_a, t_stack **stack_b,
		int *chunk_limit, int chunk_size)
{
	if (!stack_a || !stack_b || !chunk_limit)
		return ;
	if ((*stack_a)->order <= *chunk_limit)
	{
		pb(stack_a, stack_b);
		(*chunk_limit)++;
		if (*stack_b && (*stack_b)->order < *chunk_limit - chunk_size)
			rb(stack_b, 1);
	}
	else
		ra(stack_a, 1);
}

/* Divides elements into chunks and moves them from stack A to stack B
Optimizes placement in stack B to prepare for my algo part 2*/
static void	big_sort_part1(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	chunk_limit;
	int	chunk_size;

	if (!stack_a || !stack_b)
		return ;
	if (size <= 100)
		chunk_size = size * 0.15;
	else
		chunk_size = size * 0.10;
	if (chunk_size < 1)
		chunk_size = 1;
	chunk_limit = chunk_size;
	while (*stack_a)
		process_chunk_element(stack_a, stack_b, &chunk_limit, chunk_size);
}

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (!stack_a || !stack_b)
		return ;
	size = stack_size(*stack_a);
	assign_orders(stack_a, size);
	big_sort_part1(stack_a, stack_b, size);
	big_sort_part2(stack_a, stack_b);
}
