/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:22:30 by fbesson           #+#    #+#             */
/*   Updated: 2023/02/28 15:25:54 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push	*ft_create_node(int v, int i)
{
	t_push	*ptr;

	ptr = (t_push *)malloc(sizeof(t_push));
	if (ptr == NULL)
		return (NULL);
	ptr->v = v;
	ptr->i = i;
	ptr->next = NULL;
	ptr->prev = NULL;
	return (ptr);
}

void	ft_add_node(t_push **list, t_push *node)
{
	t_push	*ptr;

	if (*list == NULL)
		*list = node;
	else
	{
		ptr = *list;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = node;
		node->prev = ptr;
	}
}

void	ft_parse_input(char **av, t_push **sort_list)
{
	int	i;

	i = 1;
	*sort_list = NULL;
	while (av[i])
	{
		ft_add_node(sort_list, ft_create_node(ft_atoi(av[i]), i - 1));
		i++;
	}
}
