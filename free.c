/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:02:17 by fbesson           #+#    #+#             */
/*   Updated: 2023/03/31 19:26:12 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_push(t_push *node)
{
	t_push	*temp;

	while (node != NULL)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
}

void	ft_free_stack(t_stack *node)
{
	t_stack	*temp;

	while (node != NULL)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
}

void	ft_free_cmd(t_cmd *node)
{
	t_cmd	*temp;

	while (node != NULL)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
}

void ft_free(t_ptr *p)
{
	if (p->sort_list && *p->sort_list)
		ft_free_push(*p->sort_list);
	if (p->a && *p->a)
		ft_free_stack(*p->a);
	if (p->b && *p->b)
		ft_free_stack(*p->b);
	if (p->cmd && *p->cmd)
		ft_free_cmd(*p->cmd);
	free(p);
}
