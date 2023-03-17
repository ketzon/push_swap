/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:43:46 by fbesson           #+#    #+#             */
/*   Updated: 2023/03/17 12:28:56 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack **a;
	t_stack **b;
	t_cmd	**cmd;
	t_push **sort_list;

	/* test("hey\n"); */
	if (ac == 1)
		return (1);
	a = (t_stack **)malloc(sizeof(t_stack *));
	b = (t_stack **)malloc(sizeof(t_stack *));
	cmd = (t_cmd **)malloc(sizeof(t_stack *));
	sort_list = (t_push **)malloc(sizeof(t_push *));
	if (sort_list == NULL || a == NULL || b == NULL || cmd == NULL)
		return (1);
	ft_check_input(av);
	ft_check_size(av);
	ft_parse_input(av, sort_list);
	ft_quick_sort(*sort_list, ft_last_node(*sort_list));
	ft_parse_stack(av, a, *sort_list);
	ft_check_stack(ac, *a);
	ft_sort_low(cmd, a, b, ac);
	ft_push_swap(cmd, a, b, sort_list);
	return (0);
}

