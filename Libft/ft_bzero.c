#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

/*
#include <strings.h>
#include <stdio.h>
int main( void )
  {
    char buffer[80];

    ft_bzero (buffer, 80);
	bzero (buffer, 80);
    return (0);
  }
*/