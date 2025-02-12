/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:32:58 by mcarton           #+#    #+#             */
/*   Updated: 2025/02/12 22:04:26 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Retourne l'index du plus petit élément dans la pile
int get_min_position(t_stack *stack)
{
    t_stack *tmp;
    int min;
    int position;
    int i;

    tmp = stack;
    min = tmp->nbr;
    position = 0;
    i = 0;
    while (tmp != NULL)
    {
        if (tmp->nbr < min)
        {
            min = tmp->nbr;
            position = i;
        }
        tmp = tmp->next;
        i++;
    }
    return (position);
}

// Déplace un élément en haut de la pile
void move_to_top(t_stack **stack, int position)
{
    int size;
    
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

// Envoie le plus petit élément de la stack a vers la stack b
void push_smallest_to_b(t_stack **stack_a, t_stack **stack_b)
{
    int position;

    position = get_min_position(*stack_a);
    move_to_top(stack_a, position);
    pb(stack_a, stack_b);
} 
