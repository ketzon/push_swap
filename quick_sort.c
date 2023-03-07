/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:52:01 by fbesson           #+#    #+#             */
/*   Updated: 2023/03/07 17:54:41 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_node(t_push *left, t_push *right)
{
	int	temp;

	temp = left->value;
	left->value = right->value;
	right>value = temp;
}

t_push	*ft_create_part(t_push *start, t_push *end)
{
	t_push	*left;
	t_push	*right;
	int	pivot;

	left = start;
	right = end;
	pivot = start->value;
	while (left->i < right->i)
	{
		while (pivot < right->value)
			right = right->prev;
		while (pivot >= left->value && left->i < right->i)
			left = left->next;
		ft_swap_node(left, right);
	}
	start->value = left->value; 
	left->value = pivot; 
	return (left);
}

int	ft_quick_sort(t_push *start, t_push *end)
{
	t_push	*pivot;
	if (start->i >= end->i)
		return (0);
	pivot = ft_create_part(start, end);
	printf("%d\n", pivot->value);
}
