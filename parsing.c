/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:31:31 by fbesson           #+#    #+#             */
/*   Updated: 2023/02/27 14:47:15 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parse_input(char **av)	
{
	int	i;
	int	j;

	i = 1;
	while (av[i] != NULL)
	{
		j = 0;
		if (!av[i][j])
			ft_exit_msg(2, "Error\n", 6, 1);
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && \
				!(j == 0 && (av[i][j] == '+' || av[i][j] == '-')))
					ft_exit_msg(2, "Error\n", 6, 1);
			j++;
		}
		i++;
	}
}
