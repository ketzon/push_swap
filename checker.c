/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:31:31 by fbesson           #+#    #+#             */
/*   Updated: 2023/04/01 14:55:42 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_doublon(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i] != NULL)
	{
		j = 1;
		while (av[j])
		{
			if (j != i && ft_cmp_nb(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_zero(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '-' || av[i] == '+')
		i++;
	while (av[i] == '0' && av[i] != '\0')
		i++;
	if (av[i] != '\0')
		return (0);
	else
		return (1);
}

int	ft_check_input(char **av, t_ptr *p)
{
	unsigned int	i;
	int				zero_count;

	i = 1;
	zero_count = 0;
	while (av[i] != NULL)
	{
		if (!ft_isdigit(av[i]))
			ft_exit_msg(2, "Error\n", 1, p);
		zero_count += ft_check_zero(av[i]);
		if (zero_count >= 2)
			ft_exit_msg(2, "Error\n", 1, p);
		if (ft_check_doublon(av))
			ft_exit_msg(2, "Error\n", 1, p);
		if (ft_check_size(av))
			ft_exit_msg(2, "Error\n", 1, p);
		i++;
	}
	return (0);
}

int	ft_check_size(char **av)
{
	unsigned int	i;
	ssize_t			value;

	i = 1;
	while (av[i] != NULL)
	{
		value = ft_atoli(av[i]);
		if (value > INT_MAX || value < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_stack(int ac, t_stack *a, t_ptr *p)
{
	int	min;

	if (ac == 2)
	{
		ft_free(p);
		exit (0);
	}
	min = a->value;
	while (a->next != NULL)
	{
		if (min > a->next->value)
			return (0);
		a = a->next;
		min = a->value;
	}
	ft_free(p);
	exit (0);
}
