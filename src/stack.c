/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:21:03 by mcarton           #+#    #+#             */
/*   Updated: 2025/02/11 15:51:39 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

void	print_stack(t_stack *stack)
{
	printf("📌 Stack contents:\n");
	while (stack != NULL)
	{
		printf("Nbr = %ld et index = %ld | Previous: %p | Next: %p\n",
			stack->nbr, stack->index, stack->previous, (void *)stack->next);
		stack = stack->next;
	}
	printf("✅ Fin de la stack\n");
}

t_stack	*add_to_stack(t_stack *first, long nbr)
{
	t_stack	*new_element;
	t_stack	*tmp;

	new_element = malloc(sizeof(t_stack));
	if (new_element == NULL)
		return (first);
	new_element->nbr = nbr;
	new_element->previous = NULL;
	new_element->next = NULL;
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

t_stack	*initialize_stack(int argc, char **argv)
{
	t_stack *first;
	size_t i;

	first = NULL;

	i = 0;
	while (i < (size_t)argc)
	{
		first = add_to_stack(first, ft_atoi(argv[i]));
		i++;
	}
	print_stack(first);

	return (first);
}