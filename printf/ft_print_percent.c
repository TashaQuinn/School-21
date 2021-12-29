#include <unistd.h>

void	ft_print_percent(int *nc)
{
	write(1, "%", 1);
	*nc += 1;
}
