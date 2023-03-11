/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:06:29 by fbesson           #+#    #+#             */
/*   Updated: 2023/03/11 14:45:46 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_create_stack_node(int value)
{
	t_stack *ptr;	

	ptr = (t_stack *)malloc(sizeof(t_stack));
	if (ptr == NULL)
		return (NULL);
	ptr->a_count = 0;
	ptr->b_count = 0;
	ptr->sum = 0;
	ptr->value = value;
	ptr->next = NULL;
	return (ptr);
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

void	ft_parse_stack(char **av, t_stack **a, t_push *sort_list);
{
	int	i;
	t_push	*temp;

	i = 1;
	*a = NULL;
	temp = sort_list;
	while (av[i])
	{
		i++;
	}
}
