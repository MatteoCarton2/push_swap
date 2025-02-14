/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:21:03 by mcarton           #+#    #+#             */
/*   Updated: 2025/02/14 16:21:12 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

void	print_stack(t_stack *stack, char a_or_b)
{
	printf("📌 Stack %c\n", a_or_b);
	while (stack != NULL)
	{
		printf("Nbr = %ld et index = %ld | Previous: %p | Next: %p\n",
			stack->nbr, stack->index, stack->previous, (void *)stack->next);
		stack = stack->next;
	}
	printf("✅ Fin de la stack %c \n\n", a_or_b);
}

void update_index(t_stack *stack)
{
    int i = 0;
    while (stack)
    {
        stack->index = i;
        stack = stack->next;
        i++;
    }
}

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

// Fonction qui retourne la taille de la stack
int stack_size(t_stack *stack)
{
    int count = 0;

    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return (count);
}