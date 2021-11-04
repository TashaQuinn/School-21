#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (fd < 0)
		return ;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

/*
void ft_putchar_fd(char c, int fd)
{
	write(1, &c, 1);
}

int main()
{
	ft_putstr_fd("lalalalall", 1);
	return (0);
}
*/