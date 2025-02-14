/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:36:19 by mcarton           #+#    #+#             */
/*   Updated: 2025/02/14 16:20:52 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void big_sort(t_stack **stack_a, t_stack **stack_b)
{
    push_initial_elements(stack_a, stack_b);
    
}

//envoie 2 éléments de la stack a dans la stack b, on réfléchis pas, c'est juste pour avoir un MIN et un MAX dans stack b
void push_initial_elements(t_stack **stack_a, t_stack **stack_b)
{
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
}