#include "push_swap.h"

int	ft_exit_msg(int fd, char *msg, int len, int status)
{
	write (fd, msg, len);
	exit (status);
}

t_push	*ft_last_node(t_push *list)
{
	while (list->next != NULL)
		list = list->next;
	return (list);
}
