#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

/*
int main()
{
	ft_putchar_fd('c', 2);
	return (0);
}
*/