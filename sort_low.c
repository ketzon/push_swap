/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_low.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:41:31 by fbesson           #+#    #+#             */
/*   Updated: 2023/03/24 20:33:07 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_five(t_cmd **cmd, t_stack **a, t_stack **b, int ac)
{
	int	n0;
	int	n1;
	int	n2;
	int	temp;	

	while (ac-- > 4)
		push_b(cmd, a, b);
	n0 = (*a)->value;
	n1 = (*a)->next->value;
	n2 = (*a)->next->next->value;
	if ((n0 < n2 && n0 > n1) || (n1 > n2 && n1 < n0) || (n2 > n0 && n2 < n1))
	{
		swap_a(cmd, *a);
		temp = n0;
		n0 = n1;
		n1 = temp;
	}
	if (n2 < n0 && n2 > n1)
		rot_a(cmd, a);
	else if (n0 > n2 && n0 < n1)
		rrot_a(cmd, a);
	
}

void	ft_sort_low(t_cmd **cmd, t_stack **a, t_stack **b, int ac)
{
	if (ac == 3)
		ft_exit_msg(1, "sa\n", 3, 0);
	else if (ac <= 6)
	{
		ft_sort_five(cmd, a, b, ac);
		if (*b == NULL)
		{
			ft_print_cmd(cmd);
			exit (0);
		}
	}
}
