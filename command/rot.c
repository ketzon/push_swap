/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:23:35 by fbesson           #+#    #+#             */
/*   Updated: 2023/03/23 17:51:54 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rot_a(t_cmd **cmd, t_stack **a)
{
	t_stack *find;
	t_stack *temp;
	find = *a;
	if (find == NULL || find->next == NULL)
		return (0);
	else
	{
		temp = *a;
		*a = temp->next;
		while (find->next != NULL)
			find = find->next;
		find->next = temp;
		temp->next = NULL;
		ft_cmd_node(cmd, "ra\n");
	}
	return (0);
}

int	rot_b(t_cmd **cmd, t_stack **b)
{
	t_stack *find;	
	t_stack *temp;	

	find = *b;
	if (find == NULL || find->next == NULL)
		return (0);
	else
	{
		temp = *b;
		*b = temp->next; 
		while (find->next != NULL)
			find = find->next;
		find->next = temp;
		temp->next = NULL;
		ft_cmd_node(cmd, "rb\n");
	}
	return (0);
}

void	rot_ab(t_cmd **cmd, t_stack **a, t_stack **b)
{
	rot_a(cmd, a);
	rot_b(cmd, b);
	ft_replace_ra_rb_with_rr(cmd, "rr\n");
}

void	ft_replace_ra_rb_with_rr(t_cmd **cmd, char *rr)
{
	t_cmd *previous;
	t_cmd *last;
	
	last = *cmd;
	while (last->next != NULL)
	{
		previous = last;
		last = last->next;
	}
	free(previous->next);
	previous->next = NULL;
	previous->str = rr;
}
