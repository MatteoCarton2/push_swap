/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:12:40 by mcarton           #+#    #+#             */
/*   Updated: 2025/02/14 10:51:02 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	size_t	new_argc;
	char	**new_argv;
	t_stack	*stack_a;
	t_stack *stack_b;
	
	if (argc < 2)
		return (0);
	stack_b = NULL;
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
		
	

	printf("\n--- AVANT ---\n");
	print_stack(stack_a, 'A');
    print_stack(stack_b, 'B');
	
	printf("\n--- OPERATIONS ---\n");
	algorithm(&stack_a, &stack_b);
	
	printf("\n--- APRES ---\n");
	print_stack(stack_a, 'A');
    print_stack(stack_b, 'B');
	/*// on envoie 3 elements de A vers B pour tester rrb
    printf("\n--- PB (On envoie 3 elements de A vers B) ---\n");
    pb(&stack_a, &stack_b);
    pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);

    printf("\n--- Avant `rrr()` ---\n");
    print_stack(stack_a);
    print_stack(stack_b);

    // Appliquer rrr
    rrr(&stack_a, &stack_b);

    printf("\n--- Après `rrr()` ---\n");
    print_stack(stack_a);
    print_stack(stack_b); */

	return (0);
}
