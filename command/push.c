/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:11:50 by fbesson           #+#    #+#             */
/*   Updated: 2023/03/25 15:54:53 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push_a(t_cmd **cmd, t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*b == NULL)
		return (0);
	else
	{
		temp = *b;
		*b = temp->next;
		temp->next = *a;
		*a = temp;
		ft_cmd_node(cmd, "pa\n");
	}
	return (0);
}

int	push_b(t_cmd **cmd, t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*a == NULL)
		return (0);
	else
	{
		temp = *a;
		*a = temp->next;
		temp->next = *b;
		*b = temp;
		ft_cmd_node(cmd, "pb\n");
	}
	return (0);
}
