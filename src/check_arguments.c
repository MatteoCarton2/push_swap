/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:44:13 by mcarton           #+#    #+#             */
/*   Updated: 2025/02/11 19:17:15 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int has_duplicates(int argc, char **argv)
{
    size_t i;
    size_t j;

    i = 0;
    while (i < (size_t)argc)
    {
        j = 0;
        while (j < i)
        {
            if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

char **check_arguments(int argc, char **argv, size_t *new_argc)
{
    size_t i;
    
    i = 0;
    while (argv[i] != NULL)
    {
        if (!is_valid_args(argv[i]))
        {
            printf("INVALIDE ❌\n");
			if (argc == 2)
				(free(argv));
            return (NULL);
        }
        i++;
    }
    *new_argc = i;
    if (has_duplicates(*new_argc, argv))
    {
        printf("DOUBLON ❌\n");
		if (argc == 2)
            free(argv);
        return (NULL);
    }
    return (argv);
}