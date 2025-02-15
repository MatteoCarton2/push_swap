/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:18:29 by mcarton           #+#    #+#             */
/*   Updated: 2025/02/15 11:49:41 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_cost_a(t_stack *element, int stack_size)
{
	if (element->index <= stack_size / 2)
		return (element->index); // Si l’élément est dans la première moitié de la stack, utilisation de ra
	else
		return (stack_size - element->index); // Si l’élément est dans la seconde moitié de la stack, utilisation de rra
}