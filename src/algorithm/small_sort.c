/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:14:21 by mcarton           #+#    #+#             */
/*   Updated: 2025/02/14 17:29:24 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_stack **stack_a)
{
    t_stack	*biggest_node;

    biggest_node = find_max(*stack_a);
    if (biggest_node == *stack_a)
        ra(stack_a, 1);
    else if ((*stack_a)->next == biggest_node)
        rra(stack_a, 1);
    if ((*stack_a)->nbr > (*stack_a)->next->nbr)
        sa(stack_a, 1);
}

t_stack	*find_max(t_stack *stack)
{
	long			max;
	t_stack	*max_elem;
	if (!stack)
		return (NULL);
	max = LONG_MIN; 
	while (stack)
	{
		if (stack->nbr > max) 
		{
			max = stack->nbr;
			max_elem = stack;
		}
		stack = stack->next;
	}
	return (max_elem);
}

/* L'idée consiste à envoyer les 2 plus petits éléments(ou qu'un 1 seul si 4
éléments) dans STACK B,
	puis trier les 3 éléments restants dans STACK A avec sort_three()
avant de mettre dans STACK B */
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

// Envoie le plus petit élément de la stack a vers la stack b
void	push_smallest_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	position;

	position = get_min_position(*stack_a);
	move_to_top(stack_a, position);
	pb(stack_a, stack_b);
}

// Déplace un élément en haut de la pile
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
