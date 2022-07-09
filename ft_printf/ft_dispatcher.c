
#include "libftprintf.h"

static int	in_set(char c, char const *set)
{
	size_t	pos;

	if (!set)
		return (0);
	pos = 0;
	while (set[pos])
	{
		if (set[pos] == c)
			return (1);
		pos++;
	}
	return (0);
}

void	ft_dispatcher(va_list arg_ptr, const char *form, size_t *pos, int *nc)
{
	if (form[*pos] == 'c')
		ft_print_char((char) va_arg(arg_ptr, int), nc);
	if (form[*pos] == 's')
		ft_print_str((char *) va_arg(arg_ptr, char *), nc);
	if (form[*pos] == 'p')
		ft_print_ptr(va_arg(arg_ptr, void *), nc);
	if (form[*pos] == 'd' || form[*pos] == 'i')
		ft_print_nbr((int) va_arg(arg_ptr, int), nc);
	if (form[*pos] == 'u')
		ft_print_unsigned_nbr((unsigned int) va_arg(arg_ptr, unsigned int), nc);
	if (form[*pos] == 'x')
		ft_print_hex((unsigned long) va_arg(arg_ptr, unsigned int), nc, 0);
	if (form[*pos] == 'X')
		ft_print_hex((unsigned long) va_arg(arg_ptr, unsigned int), nc, 1);
	if (form[*pos] == '%')
		ft_print_percent(nc);
	if (!in_set(form[*pos], "cspdiuxX%"))
	{	
		write(1, "%", 1);
		*nc += 1;
		return ;
	}
	*pos = *pos + 1;
}
