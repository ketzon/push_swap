/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   division.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:15:31 by fbesson           #+#    #+#             */
/*   Updated: 2023/03/23 17:24:38 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_fix_clock(int index, int cw_index, int ccw_index)
{
	if (cw_index == ccw_index)
	{
		if (cw_index == -1)
			return (2);
		else if(cw_index < index / 2)
			return (1);
		else
			return (0);

	}
	else if (cw_index < index - ccw_index)
		return (1);
	else
		return (0);
}

int	ft_short_rot(t_stack *a, int min, int max)
{
	int	index;
	int	cw_index;
	int	ccw_index;

	index = 0;
	cw_index = -1;
	ccw_index = -1;
	while (a != NULL)
	{
		if (a->value >= min && a->value <= max)
			ccw_index = index;
		if (cw_index == -1 && (a->value >= min && a->value <= max))
			cw_index = index;
		a = a->next;
		index++;
	}
	return (ft_fix_clock(index, cw_index, ccw_index));
}

void	ft_quick_rot(t_cmd **cmd, t_stack **a, t_stack **b, t_push *sort_list)
{
	int	index;
	static int	min;
	static int 	max;

	if (max != 0)
	{
		min = sort_list->pivot1;
		max = sort_list->pivot2;
	}
	else
		max = sort_list->pivot1;
	while (1)
	{
		index = ft_short_rot(*a, min, max);
		if (index == 1)
			ft_clockwise(cmd, a, b, max);
		else if(index == 0)
			ft_cclockwise(cmd, a, b, max);
		else
			break ;
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
		push_b(cmd, a, b);
}
