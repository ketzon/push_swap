/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:06:29 by fbesson           #+#    #+#             */
/*   Updated: 2023/03/11 15:41:59 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_create_stack_node(int value)
{
	t_stack *node;	

	node = (t_stack *)malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->a_count = 0;
	node->b_count = 0;
	node->sum = 0;
	node->value = value;
	node->next = NULL;
	return (node);
}

void	ft_add_stack_node(t_stack **list, t_stack *node)
{
	t_stack	*temp;

	if (*list == NULL)
		*list = node;
	else
	{
		temp = *list;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = node;
	}
}

void	ft_parse_stack(char **av, t_stack **a, t_push *sort_list)
{
	int	i;
	t_push	*begin;

	i = 1;
	*a = NULL;
	begin = sort_list;
	while (av[i])
	{
		sort_list = begin;
		while (sort_list != NULL && sort_list->value != ft_atoi(av[i]))
			sort_list = sort_list->next;
		ft_add_stack_node(a, ft_create_stack_node(sort_list->i));
		i++;
	}
	while (begin != NULL)
	{
		begin->value = begin->i;
		begin = begin->next;
		printf("dess");
	}
}
