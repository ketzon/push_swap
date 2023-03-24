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


ssize_t	ft_atoli(const char *str)
{
	int	i;
	int	neg;
	ssize_t	res;

	i = 0;
	neg = 1;
	res = 0;
	if (!str)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	if (res > 9223372036854775807 && neg == -1)
		return (0);
	else if (res > 9223372036854775807)
		return (-1);
	return (res * neg);
}
