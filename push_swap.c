/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:43:46 by fbesson           #+#    #+#             */
/*   Updated: 2023/02/23 18:08:47 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_vars	value;	
	int	i;

	i = 0;
	if (ac < 2)
	{
		printf("Error\n");
	}
	else
	{
		while (i < ac)
		{
			value.stack_a = atoi(av[i]);
			ft_printf("%d\n", value.stack_a);
			i++;
		}
		write (1, "\n", 1);
	}
}
