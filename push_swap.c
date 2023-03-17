/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:30:53 by fbesson           #+#    #+#             */
/*   Updated: 2023/03/17 14:45:57 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_cmd **cmd, t_stack **a, t_stack **b, t_push **sort_list)
{
	if (*b == NULL)
	{
		ft_division(cmd, a, b, sort_list);
	}
}
