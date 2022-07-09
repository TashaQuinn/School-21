#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_dispatcher(va_list arg_ptr, const char *form, size_t *pos, int *nc);
void	ft_print_char(char c, int *nc);
void	ft_print_str(char *str, int *nc);
void	ft_print_nbr(int nbr, int *nc);
void	ft_print_unsigned_nbr(unsigned int nbr, int *nc);
void	ft_print_hex(unsigned long nbr, int *nc, unsigned char iscapital);
void	ft_print_ptr(void *prt, int *nc);
void	ft_print_percent(int *nc);
#endif