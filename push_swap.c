/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:43:46 by fbesson           #+#    #+#             */
/*   Updated: 2023/03/08 13:52:21 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_push **sort_list;
	sort_list = malloc(sizeof(t_push *));
	if (sort_list == NULL || ac == 1)
		return (1);
	ft_check_input(av);
	ft_check_size(av);
	ft_parse_input(av, sort_list);
	ft_quick_sort(*sort_list, ft_last_node(*sort_list));
	return (0);
}

