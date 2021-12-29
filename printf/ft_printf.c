#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	int		num_chars;
	size_t	pos;
	va_list	arg_ptr;

	if (!format || (*format == '%' && !format[1]))
		return (-1);
	num_chars = 0;
	pos = 0;
	va_start(arg_ptr, format);
	while (format[pos])
	{
		if (format[pos] != '%')
		{
			write(1, &format[pos], 1);
			num_chars++;
			pos++;
		}
		else
		{
			pos++;
			ft_dispatcher(arg_ptr, format, &pos, &num_chars);
		}	
	}
	va_end(arg_ptr);
	return (num_chars);
}
