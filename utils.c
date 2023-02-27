#include "push_swap.h"

int	ft_exit_msg(int fd, char *msg, int len, int status)
{
	write (fd, msg, len);
	exit (status);
}
