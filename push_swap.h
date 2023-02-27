/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:43:51 by fbesson           #+#    #+#             */
/*   Updated: 2023/02/27 15:16:51 by fbesson          ###   ########.fr       */
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

void	ft_parse_input(char **av);
int	ft_exit_msg(int fd, char *msg, int len, int status);
void	ft_parse_size(char **av);	

typedef struct	s_vars {
int	stack_a;
} t_vars;

#endif
