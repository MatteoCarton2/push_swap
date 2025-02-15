/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:00:28 by mcarton           #+#    #+#             */
/*   Updated: 2025/02/14 17:29:29 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	algorithm(t_stack **stack_a, t_stack **stack_b)
{
    (void)stack_b;
    int size;

    size = stack_size(*stack_a);
	if (is_sorted(stack_a)) // check si la stack a de base est déja trié (si oui, rien à faire)
    {
        printf("La stack est déja triée ✅\n\n");
        return;
    }
    if (size == 2)
        sa(stack_a, 1); /* si la stack contient que 2 éléments faut inverser (forcément en désordre car on a check juste au dessus si c'était déja trié ou non) */ 
    else if (size == 3)
        sort_three(stack_a);
    else if (size <= 5) // si c'est 4 ou 5
        sort_four_or_five(stack_a, stack_b);
    else
        big_sort(stack_a, stack_b);
}

/* Fonction qui vérifie si la stack est triée */
int is_sorted(t_stack **stack_a)
{
    t_stack *tmp;

    if (!(*stack_a) || !(*stack_a)->next) /* si la stack est vide ou qu'elle a que 1 élément, elle est d'office trié */ 
        return (1);
    tmp = *stack_a;
    while(tmp->next != NULL)
    {
        if (tmp->nbr > tmp->next->nbr) /* si le nombre avant est plus grand, c'est que c'est pas trié "7 2" */ 
            return (0);
        tmp = tmp->next;
    }
    return (1);
}