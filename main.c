/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:43:46 by fbesson           #+#    #+#             */
/*   Updated: 2023/03/31 20:03:45 by fbesson          ###   ########.fr       */
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

void	ft_sort_low(t_cmd **cmd, t_stack **a, t_stack **b, int ac, t_ptr *p)
{
	if (ac == 3)
		ft_exit_msg(1, "sa\n", 3, 0, p);
	else if (ac <= 6)
	{
		ft_sort_five(cmd, a, b, ac);
		if (*b == NULL)
			ft_exit_cmd(cmd, 0, p);
	}
}

int	main(int ac, char **av)
{
	t_ptr 	*p;

	if (ac == 1)
		return (1);
	p = (t_ptr *)malloc(sizeof(t_ptr));
	p->a = (t_stack **)malloc(sizeof(t_stack *));
	p->b = (t_stack **)malloc(sizeof(t_stack *));
	p->cmd = (t_cmd **)malloc(sizeof(t_stack *));
	p->sort_list = (t_push **)malloc(sizeof(t_push *));
	if (p == NULL || p->sort_list == NULL || p->a == NULL || p->b == NULL || p->cmd == NULL)
		return (1);
	ft_check_input(av, p);
	ft_parse_input(av, p->sort_list);
	ft_quick_sort(*p->sort_list, ft_last_node(*p->sort_list));
	ft_parse_sort(av, p->a, *p->sort_list);
	ft_check_stack(ac, *p->a, p);
	ft_sort_low(p->cmd, p->a, p->b, ac, p);
	ft_push_swap(p->cmd, p->a, p->b, p->sort_list, p);
	return (0);
}
