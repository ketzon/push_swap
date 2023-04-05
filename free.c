/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:02:17 by fbesson           #+#    #+#             */
/*   Updated: 2023/04/05 12:45:18 by fbesson          ###   ########.fr       */
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

void	ft_free_av(char **av)
{
	int	i;

	i = 0;
	while (av && av[i])
	{
		free(av[i]);
		i++;
	}
}

void	ft_free(t_ptr *p)
{
	if (p->sort_list && *p->sort_list)
		ft_free_push(*p->sort_list);
	if (p->a && *p->a)
		ft_free_stack(*p->a);
	if (p->b && *p->b)
		ft_free_stack(*p->b);
	if (p->cmd && *p->cmd)
		ft_free_cmd(*p->cmd);
	if (p->av && *p->av)
		ft_free_av(p->av);
	free(p->sort_list);
	free(p->a);
	free(p->b);
	free(p->cmd);
	free(p->av);
	free(p);
}
