/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:21:03 by mcarton           #+#    #+#             */
/*   Updated: 2025/04/10 14:53:26 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*initialize_stack(int argc, char **argv)
{
	t_stack	*first;
	size_t	i;

	first = NULL;
	i = 0;
	while (i < (size_t)argc)
	{
		first = add_to_stack(first, ft_atoi(argv[i]));
		if (first == NULL)
			return (NULL);
		i++;
	}
	return (first);
}

t_stack	*add_to_stack(t_stack *first, long nbr)
{
	t_stack	*new_element;
	t_stack	*tmp;

	new_element = malloc(sizeof(t_stack));
	if (new_element == NULL)
		return (NULL);
	new_element->nbr = nbr;
	new_element->next = NULL;
	new_element->previous = NULL;
	if (first == NULL)
		return (new_element);
	tmp = first;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_element;
	new_element->previous = tmp;
	new_element->index = tmp->index + 1;
	return (first);
}
