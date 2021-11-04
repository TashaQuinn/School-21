#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/*
void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void ft_putstr_fd(char *s, int fd)
{
	int i = 0;

	while(s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

int main()
{
	ft_putendl_fd("lalalalall", 1);
	return (0);
}
*/