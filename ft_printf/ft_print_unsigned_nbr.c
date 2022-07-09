#include <unistd.h>

void	ft_print_unsigned_nbr(unsigned int nbr, int *nc)
{
	long			n;
	unsigned char	c;

	n = (long) nbr;
	if (n < 10)
	{
		c = '0' + (char) n;
		write(1, &c, 1);
		(*nc)++;
		return ;
	}
	ft_print_unsigned_nbr((n - n % 10) / 10, nc);
	c = '0' + (char)(n % 10);
	write(1, &c, 1);
	(*nc)++;
}
