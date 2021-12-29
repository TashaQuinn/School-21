#include <unistd.h>

static void		ft_putstr(char *s);
static size_t	ft_strlen(const char *s);

void	ft_print_str(char *str, int *nc)
{
	if (!str)
	{
		write(1, "(null)", 6);
		*nc += 6;
		return ;
	}
	ft_putstr(str);
	*nc += (int) ft_strlen(str);
}

static void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

static size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s != 0)
	{
		i++;
		s++;
	}
	return (i);
}
