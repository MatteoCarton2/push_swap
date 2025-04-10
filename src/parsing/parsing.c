/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:02:11 by mcarton           #+#    #+#             */
/*   Updated: 2025/04/10 16:19:41 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	**check_arguments(int argc, char **argv, size_t *new_argc)
{
	size_t	i;

	i = 0;
	while (argv[i] != NULL)
	{
		if (!is_valid_args(argv[i]))
		{
			ft_putstr_fd("Error\n", 2);
			if (argc == 2)
				(free(argv));
			return (NULL);
		}
		i++;
	}
	*new_argc = i;
	if (has_duplicates(*new_argc, argv) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		if (argc == 2)
			free(argv);
		return (NULL);
	}
	return (argv);
}

static int	is_int_overflow(char *str)
{
	long	value;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	value = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = value * 10 + (str[i] - '0');
		if ((sign == 1 && value > INT_MAX) || (sign == -1 && - value < INT_MIN))
			return (1);
		i++;
	}
	return (0);
}

int	is_valid_args(char *str)
{
	size_t	i;

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
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	if (is_int_overflow(str) == 1)
		return (0);
	return (1);
}

int	has_duplicates(int argc, char **argv)
{
	size_t	i;
	size_t	j;

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
