/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:12:40 by mcarton           #+#    #+#             */
/*   Updated: 2025/02/10 17:08:32 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	size_t	i;

	if (argc < 2)
		return (0);
	i = 1;
	while (i < (size_t)argc)
	{
		if (is_valid_args(argv[i]) == 0)
		{
			printf("INVALIDE ❌\n");
			return (0);
		}
		i++;
	}
	if (has_duplicates(argc, argv) == 1)
	{
		printf("DOUBLON ❌\n");
		return (0);
	}
	printf("VALIDE ✅\n");
	initialize_stack(argc, argv);
	return (0);
}
