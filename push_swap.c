/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:12:40 by mcarton           #+#    #+#             */
/*   Updated: 2025/02/09 16:52:47 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
    int i;

    if (argc < 2)
        return (0);
    i = 1;
    while (i < argc)
    {
        if (is_valid_args(argv[i]) == 0)
        {
             printf("❌");
            return (0);
        }
        i ++;
    }
    printf("✅");
	return (0);
}
