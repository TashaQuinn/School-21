#include <unistd.h>

void	ft_print_char(char c, int *nc)
{
	write(1, &c, 1);
	*nc = *nc + 1;
}
