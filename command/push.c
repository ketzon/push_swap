/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:11:50 by fbesson           #+#    #+#             */
/*   Updated: 2023/03/16 18:36:32 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_b(t_cmd **cmd, t_stack **a, t_stack **b);
{
	t_stack	*temp;

	if (*a == NULL)
		return (0);
	else
	{
		temp = *a;
		*a = temp->next;
		temp->next = *b;
		*b = temp;
	}
	return (0);
		
}
int	test(char *str)
{
	ft_exit_msg(2, str, ft_strlen(str), 1);
	return (0);
}
