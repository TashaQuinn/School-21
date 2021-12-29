#include <unistd.h>
#include "libftprintf.h"

static char	ft_dec2hex(unsigned char nbr, unsigned char iscapital);

void	ft_print_hex(unsigned long nbr, int *nc, unsigned char iscapital)
{
	unsigned char	c;

	if (nbr < 16)
	{
		c = ft_dec2hex((unsigned char) nbr, iscapital);
		write(1, &c, 1);
		*nc += 1;
		return ;
	}
	ft_print_hex((nbr - nbr % 16) / 16, nc, iscapital);
	c = ft_dec2hex((unsigned char) nbr % 16, iscapital);
	write(1, &c, 1);
	*nc += 1;
}

static char	ft_dec2hex(unsigned char nbr, unsigned char iscapital)
{
	char	offset;

	if (iscapital)
		offset = 'A';
	else
		offset = 'a';
	if (nbr >= 10)
		return (nbr - 10 + offset);
	return (nbr + '0');
}
