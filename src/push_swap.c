/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:12:40 by mcarton           #+#    #+#             */
/*   Updated: 2025/04/10 17:59:33 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static void	process_stacks(t_stack *stack_a, t_stack *stack_b, char **new_argv,
		int argc)
{
	algorithm(&stack_a, &stack_b);
	if (argc == 2)
		free_split(new_argv);
	free_stack(stack_a);
	free_stack(stack_b);
}

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
			free_split(new_argv);
		return (0);
	}
	stack_b = NULL;
	process_stacks(stack_a, stack_b, new_argv, argc);
	return (0);
}
