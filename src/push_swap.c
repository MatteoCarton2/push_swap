/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:12:40 by mcarton           #+#    #+#             */
/*   Updated: 2025/02/11 15:51:48 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	size_t	new_argc;
	char	**new_argv;
	t_stack	*stack_a;

	if (argc < 2)
		return (0);
	if (argc == 2)
		new_argv = ft_split(argv[1], ' '); // on split si 1 seul argument "7 4 -23"
	else
		new_argv = argv + 1; // sinon on garde argv + 1 ???
	new_argv = check_arguments(argc, new_argv, &new_argc);
	if (new_argv == NULL)
		return (0);
	stack_a = initialize_stack(new_argc, new_argv);
	if (!stack_a)
	{
		printf("Erreur allocation stack ❌\n");
		if (argc == 2)
			free(new_argv);
		return (0);
	}
	if (argc == 2)
		free(new_argv);
	return (0);
}
