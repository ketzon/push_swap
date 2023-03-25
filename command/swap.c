/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:11:40 by fbesson           #+#    #+#             */
/*   Updated: 2023/03/25 15:59:20 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	swap_a(t_cmd **cmd, t_stack *a)
{
	int	temp;

	if (a == NULL || a->next == NULL)
		return (0);
	else
	{
		temp = a->value;
		a->value = a->next->value;
		a->next->value = temp;
		ft_cmd_node(cmd, "sa\n");
	}
	return (0);
}

int	swap_b(t_cmd **cmd, t_stack *b)
{
	int	temp;

	if (b == NULL || b->next == NULL)
		return (0);
	else
	{
		temp = b->value;
		b->value = b->next->value;
		b->next->value = temp;
		ft_cmd_node(cmd, "sb\n");
	}
	return (0);
}

void	swap_ab(t_cmd **cmd, t_stack *a, t_stack *b)
{
	swap_a(cmd, a);
	swap_b(cmd, b);
	ft_replace_cmd(cmd, "ss\n");
}
