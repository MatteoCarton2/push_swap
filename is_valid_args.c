/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:33:55 by mcarton           #+#    #+#             */
/*   Updated: 2025/02/09 15:55:51 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Vérifie si une chaîne est un nombre valide :
   - Accepte un seul signe `+` ou `-` au début (pas "--42" ou "++42")
   - Doit contenir au moins un chiffre après le signe (pas juste "+" ou "-")
   - Tous les caractères après le signe doivent être des chiffres */
int	is_valid_args(char *str)
{
	size_t i;
	if (str == NULL || str[0] == '\0')
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+') 
	{
		i++;
		if (str[i] == '\0')
			return (0);
	}
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57) // = n'est pas un numéro
			return (0);
		i++;
	}
	return (1);
}