/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:43:46 by fbesson           #+#    #+#             */
/*   Updated: 2023/03/12 12:06:07 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack **a;
	t_push **sort_list;

	a = (t_stack **)malloc(sizeof(t_stack *));
	sort_list = (t_push **)malloc(sizeof(t_push *));
	if (sort_list == NULL || a == NULL || ac == 1)
		return (1);
	ft_check_input(av);
	ft_check_size(av);
	ft_parse_input(av, sort_list);
	ft_quick_sort(*sort_list, ft_last_node(*sort_list));
	ft_parse_stack(av, a, *sort_list);
	ft_check_stack(ac, *a);
	return (0);
}

