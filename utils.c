#include "push_swap.h"

int	ft_exit_msg(int fd, char *msg, int len, int status)
{
	write (fd, msg, len);
	exit (status);
}

t_push	*ft_last_node(t_push *node)
{
	while (node->next != NULL)
		node = node->next;
	return (node);
}

int	ft_abs(int v)
{
	if (v < 0)
		return (-v);
	else
		return (v);
}

//faire atoi qui gere les long int
