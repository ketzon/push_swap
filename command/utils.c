/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:35:43 by fbesson           #+#    #+#             */
/*   Updated: 2023/03/24 12:56:36 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_print_cmd(t_cmd **cmd)
{
	t_cmd	*node;

	node = *cmd;
	while (node != NULL)
	{
		ft_printf("%s", node->str);
		node = node->next;
	}
}

void	ft_cmd_node(t_cmd **cmd, char *moove)
{
	t_cmd	*node;
	t_cmd	*ptr;

	node = malloc(sizeof(t_cmd));
	if (!node)
		exit(0);
	node->str = moove;
	node->next = NULL;
	if(*cmd == NULL)
		*cmd = node;
	else
	{
		ptr = *cmd;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = node;
	}
}
