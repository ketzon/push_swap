/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:30:53 by fbesson           #+#    #+#             */
/*   Updated: 2023/03/25 11:05:26 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_calc_rot_a(t_stack *a, int target)
{
	int	len;
	int	index;
	t_stack *node;

	len = 0;
	index = 0;
	node = a;
	while (a != NULL)
	{
		a = a->next;
		len++;
	}
	while (node != NULL)
	{
		if (node->value == target)
		{
			if (len / 2 < index)
				return (index - len);
			else
				return (index);
		}
		node = node->next;
		index++;
	}
	return (0);
}

void	ft_calc_rot_b(t_stack *b)
{
	int	len;
	int	index;
	t_stack	*node;

	len = 0;
	index = 0;
	node = b;
	while (b != NULL)
	{
		b = b->next;
		len++;
	}
	while (node != NULL)
	{
		if (len / 2 < index)
			node->b_count = index - len;
		else
			node->b_count = index;
		node = node->next;
		index++;
	}
}
int	ft_find_target(t_stack *a, int b)
{
	int	min;
	int	begin;

	min = ft_check_max_min(a, b);
	if (min >= 0)
		return (min);
	begin = a->value;
	while (a->next != NULL)
	{
		if (b > a->value && b < a->next->value)
			return (a->next->value);
		a = a->next;
	}
	if (begin < a->value)
		return (a->value);
	else
		return (begin);
}

void	ft_sort_stack(t_cmd **cmd, t_stack **a, t_stack **b)
{
	t_stack *node;
	int	target;

	node = *b;
	ft_calc_rot_b(node);
	while (node != NULL)
	{
		target = ft_find_target(*a, node->value);
		node->a_count = ft_calc_rot_a(*a, target);
		if ((node->a_count < 0 && node->b_count < 0) || \
			(node->a_count > 0 && node->b_count > 0))
		{
			if (ft_abs(node->a_count) > ft_abs(node->b_count))
				node->sum = ft_abs(node->a_count);
			else
				node->sum = ft_abs(node->b_count);
		}
		else
			node->sum = ft_abs(node->a_count) + ft_abs(node->b_count);
		node = node->next;
	}
	ft_rot_stack(cmd, a, b);
	push_a(cmd, a, b);
}

void	ft_push_swap(t_cmd **cmd, t_stack **a, t_stack **b, t_push **sort_list)
{
	int	rotation_value;
	if (*b == NULL)
	{
		ft_division(cmd, a, b, sort_list);
		if (*a == NULL)
			push_a(cmd, a, b);
	}
	while (*b != NULL)
		ft_sort_stack(cmd, a, b);
	rotation_value = ft_calc_rot_a(*a, 0);
	if (rotation_value < 0)
		while ((*a)->value != 0)
			rrot_a(cmd, a);
	else
		while ((*a)->value != 0)
			rot_a(cmd, a);
	ft_print_cmd(cmd);
}
