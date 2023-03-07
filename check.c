/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:31:31 by fbesson           #+#    #+#             */
/*   Updated: 2023/03/07 17:35:48 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_input(char **av)	
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
	return ;
}

void	ft_check_size(char **av)
{
	unsigned int i;
	ssize_t	value;

	i = 1;
	while (av[i] != NULL)
	{
		value = (long int)ft_atoi(av[i]);
		if (value > INT_MAX || value < INT_MIN)
			ft_exit_msg(2, "Error\n", 6, 1);
		i++;
	}
}
