/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:23:39 by fbesson           #+#    #+#             */
/*   Updated: 2023/03/25 15:59:01 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rrot_ab(t_cmd **cmd, t_stack **a, t_stack **b)
{
	rrot_a(cmd, a);
	rrot_b(cmd, b);
	ft_replace_cmd(cmd, "rrr\n");
	return (0);
}

int	rrot_a(t_cmd **cmd, t_stack **a)
{
	t_stack	*find;
	t_stack	*previous;

	find = *a;
	if (find == NULL || find->next == NULL)
		return (0);
	else
	{
		while (find->next != NULL)
		{
			previous = find;
			find = find->next;
		}
		find->next = *a;
		*a = find;
		previous->next = NULL;
		ft_cmd_node(cmd, "rra\n");
	}
	return (0);
}

int	rrot_b(t_cmd **cmd, t_stack **b)
{
	t_stack	*previous;
	t_stack	*find;

	find = *b;
	if (find == NULL || find->next == NULL)
		return (0);
	else
	{
		while (find->next != NULL)
		{
			previous = find;
			find = find->next;
		}
		find->next = *b;
		*b = find;
		previous->next = NULL;
		ft_cmd_node(cmd, "rrb\n");
	}
	return (0);
}
