/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:15:31 by fbesson           #+#    #+#             */
/*   Updated: 2023/03/17 19:19:12 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_short_rot(t_stack *a, int min, int max)
{
	
}
void	ft_quick_rot(t_cmd **cmd, t_stack **a, t_stack **b, t_push **sort_list)
{
	int	i;
	static int	min;
	static int 	max;

	if (max != 0)
	{
		min = sort_list->pivot1;
		max = sort_list->pivot2;
	}
	else
		max = sort_list->piv1;
	while (1)
	{
		i = ft_short_rot(*a, min, max);	
		if (i == 1)
			(void);
		else
			break;
	}
	
}

void	ft_division(t_cmd **cmd, t_stack **a, t_stack **b, t_push **sort_list)
{
	t_push *current;

	current = *sort_list;
	while (current->next != NULL)
		current = current->next;
	if (current->i > 99)
	{
		(*sort_list)->pivot1 = current->i / 3;
		(*sort_list)->pivot2 = current->i / 3 * 2;
		ft_quick_rot(cmd, a, b, *sort_list);
		ft_quick_rot(cmd, a, b, *sort_list);
	}
	while (*a != NULL)
	{
		push_b(cmd, a, b);
	}
}
