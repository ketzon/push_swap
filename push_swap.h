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
	int	value;
}	t_push;

void	ft_check_input(char **av);
int	ft_exit_msg(int fd, char *msg, int len, int status);
void	ft_check_size(char **av);	
void	ft_parse_input(char **av, t_push **sort_list);
t_push 	*ft_create_node(int value, int i);
void	ft_add_node(t_push **list, t_push *node);
void	ft_parse_input(char **av, t_push **sort_list);
t_push	*ft_last_node(t_push *list);
void	ft_swap_node(t_push *left, t_push *right);
t_push	*partition(t_push *start, t_push *end);
int	ft_quick_sort(t_push *start, t_push *end);

#endif
