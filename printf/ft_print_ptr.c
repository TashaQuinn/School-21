#include "libftprintf.h"

#if __linux__

void	ft_print_ptr(void *ptr, int *nc)
{
	if (!ptr)
	{
		write(1, "(nil)", 5);
		*nc += 5;
		return ;
	}
	write(1, "0x", 2);
	*nc += 2;
	ft_print_hex((unsigned long) ptr, nc, 0);
}

#else

void	ft_print_ptr(void *ptr, int *nc)
{
	write(1, "0x", 2);
	*nc += 2;
	ft_print_hex((unsigned long) ptr, nc, 0);
}

#endif
