/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:36:39 by fbesson           #+#    #+#             */
/*   Updated: 2023/03/23 17:54:14 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_clockwise(t_cmd **cmd, t_stack **a, t_stack **b, int max)
{
	while ((*a)->value > max)
	{
		if (*b != NULL && (*b)->next != NULL && ((*b)->value < (*b)->next->value))
			rot_ab(cmd, a, b);
		else
			rot_a(cmd, a);
	}
	push_b(cmd, a, b);
}

void	ft_cclockwise(t_cmd **cmd, t_stack **a, t_stack **b, int max)
{
	t_stack *last_b;

	last_b = *b;
	while (*b != NULL && last_b->next != NULL)
		last_b = last_b->next;
	while ((*a)->value > max)
	{
		if (*b != NULL && (*b)->next != NULL && ((*b)->value < last_b->value))
			rrot_ab(cmd, a, b);
		else
			rrot_a(cmd, a);
	}
	push_b(cmd, a, b);
}
