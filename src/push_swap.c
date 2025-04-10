/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:12:40 by mcarton           #+#    #+#             */
/*   Updated: 2025/04/10 16:20:25 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	size_t	new_argc;
	char	**new_argv;
	t_stack	*stack_a;
	t_stack	*stack_b;
	if (argc < 2)
		return (0);
	if (argc == 2)
		new_argv = ft_split(argv[1], ' ');
	else
		new_argv = argv + 1;
	new_argv = check_arguments(argc, new_argv, &new_argc);
	if (new_argv == NULL)
		return (0);
	stack_a = initialize_stack(new_argc, new_argv);
	if (!stack_a)
	{
		ft_putstr_fd("Error\n", 2);
		if (argc == 2)
			free(new_argv);
		return (0);
	}
	if (argc == 2)
		free(new_argv);
	stack_b = NULL;
	algorithm(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
