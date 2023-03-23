/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:19:03 by fbesson           #+#    #+#             */
/*   Updated: 2023/03/23 15:30:35 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rot_stack2(t_cmd **cmd, t_stack **a, t_stack **b, t_stack *node)
{
	while (node->b_count < 0)
	{
		rrot_b(cmd, b);
		node->b_count += 1;
	}
	while (node->b_count > 0)
	{
		rot_b(cmd, b);
		node->b_count -= 1;
	}
	while (node->a_count < 0)
	{
		rrot_a(cmd, a);
		node->a_count += 1;
	}
	while (node->a_count > 0)
	{
		rot_a(cmd, a);
		node->a_count -= 1;
	}
}
void	ft_rot_stack(t_cmd **cmd, t_stack **a, t_stack **b)
{
	t_stack *node;

	node = find_min_count(*b);
	while (node->a_count > 0 && node->b_count > 0)
	{
		/* rot_ab(cmd, a, b); */
		node->a_count -= 1;
		node->b_count -= 1;
	}
	while (node->a_count < 0 && node->b_count < 0)
	{
		rrot_ab(cmd, a, b);
		node->a_count += 1;
		node->b_count += 1;
	}
	ft_rot_stack2(cmd, a, b, node);
}

t_stack *find_min_count(t_stack *b)
{
	int	min;
	int	current;
	t_stack	*min_ptr;

	min = b->sum;
	min_ptr = b;
	while (b != NULL)
	{
		current = b->sum;
		if (min > current)
		{
			min_ptr = b;
			min = current;
		}
		b = b->next;
	}
	return (min_ptr);
}
