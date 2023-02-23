/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:43:46 by fbesson           #+#    #+#             */
/*   Updated: 2023/02/23 14:34:31 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, int **av)
{
	ft_printf("test\n");
	printf("test2\n");
	char **res = ft_split("je suis florian", 'o');
	int i = 0;
	while (res[i])
	{
		printf("%s\n", res[i]);
		i++;
	}
	printf("error\n");
	return (0);
}
