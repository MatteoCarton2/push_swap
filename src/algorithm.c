/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:00:28 by mcarton           #+#    #+#             */
/*   Updated: 2025/02/12 18:07:20 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algorithm(t_stack **stack_a, t_stack **stack_b)
{
    (void)stack_b;
	if (is_sorted(stack_a))
    {
        printf("La stack est triée\n");
        return;
    }
	
}

int is_sorted(t_stack **stack_a)
{
    t_stack *tmp;

    if (!(*stack_a) || !(*stack_a)->next) // si la stack est vide ou qu'elle a que 1 élément, elle est d'office trié
        return (1);
    tmp = *stack_a;
    while(tmp->next != NULL)
    {
        if (tmp->nbr > tmp->next->nbr) // si le nombre avant est plus grand, c'est que c'est pas trié "7 2"
            return (0);
        tmp = tmp->next;
    }
    return (1);
}