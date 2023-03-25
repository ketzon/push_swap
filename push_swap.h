/* ************************************************************************** */
/*                                                                            */ /*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:43:51 by fbesson           #+#    #+#             */
/*   Updated: 2023/02/28 15:38:56 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/printf.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

enum size {
    INT_MAX = 2147483647,
    INT_MIN = -2147483648
};

typedef struct s_push 
{
	struct s_push *next;
	struct s_push *prev;
	int	i;
	int	pivot1;
	int	pivot2;
	int	value;
}	t_push;


typedef struct s_stack
{
	struct s_stack *next;
	int	a_count;	
	int	b_count;
	int	value;
	int	sum;
}	t_stack;

typedef struct s_cmd
{
	struct s_cmd *next;
	char	*str;
}	t_cmd;

void	ft_sort_five(t_cmd **cmd, t_stack **a, t_stack **b, int ac);
void	ft_parse_stack(char **av, t_stack **a, t_push *sort_list);
int	ft_exit_msg(int fd, char *msg, int len, int status);
int	push_b(t_cmd **cmd, t_stack **a, t_stack **b);
int	push_a(t_cmd **cmd, t_stack **a, t_stack **b);
void	ft_parse_input(char **av, t_push **sort_list);
void	ft_parse_input(char **av, t_push **sort_list);
t_push	*ft_partition(t_push *start, t_push *end);
int	ft_quick_sort(t_push *start, t_push *end);
void	ft_swap_node(t_push *left, t_push *right);
void	ft_add_node(t_push **list, t_push *node);
void	ft_cmd_node(t_cmd **cmd, char *moove);
int	ft_check_stack(int ac, t_stack *a);
t_push 	*ft_create_node(int value, int i);
t_push	*ft_last_node(t_push *node);
void	ft_check_input(char **av);
void	ft_print_cmd(t_cmd **av);
void	ft_check_size(char **av);	
int	swap_a(t_cmd **cmd, t_stack *a);
int	swap_b(t_cmd **cmd, t_stack *b);
int	rot_a(t_cmd **cmd, t_stack **a);
int	rot_b(t_cmd **cmd, t_stack **b);
int	rrot_a(t_cmd **cmd, t_stack **a);
int	rrot_b(t_cmd **cmd, t_stack **b);
int	rrot_ab(t_cmd **cmd, t_stack **a, t_stack **b); 
void	ft_push_swap(t_cmd **cmd, t_stack **a, t_stack **b, t_push **sort_list);
void	ft_division(t_cmd **cmd, t_stack **a, t_stack **b, t_push **sort_list);
void	ft_sort_low(t_cmd **cmd, t_stack **a, t_stack **b, int ac);
int	ft_find_target(t_stack *a, int b);
int	ft_check_max_min(t_stack *a, int b);
int	ft_calc_rot_a(t_stack *a, int target);
void	ft_calc_rot_b(t_stack *b);
void	ft_rot_stack(t_cmd **cmd, t_stack **a, t_stack **b);
t_stack *find_min_count(t_stack *b);
int	ft_abs(int v);
void	ft_clockwise(t_cmd **cmd, t_stack **a, t_stack **b, int max);
void	ft_cclockwise(t_cmd **cmd, t_stack **a, t_stack **b, int max);
void	rot_ab(t_cmd **cmd, t_stack **a, t_stack **b);
void	ft_replace_cmd(t_cmd **cmd, char *moove);
ssize_t	ft_atoli(const char *str);
void	swap_ab(t_cmd **cmd, t_stack *a, t_stack *b);

#endif
