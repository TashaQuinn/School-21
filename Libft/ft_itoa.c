#include "libft.h"

static size_t	ft_nb_length(int nb)
{
	size_t	len;

	len = 0;
	if (nb <= 0)
		len = 1;
	while (nb)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t		length;
	long int	nb;
	char		*str;

	length = ft_nb_length(n);
	nb = n;
	str = malloc(sizeof(char) * length + 1);
	if (!(str))
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		str[0] = '0';
	str[length--] = '\0';
	while (nb)
	{
		str[length] = nb % 10 + '0';
		nb = nb / 10;
		length--;
	}
	return (str);
}

/*
#include <stdio.h>
int main()
{
	char *str;

	str = (char *)ft_itoa(sizeof(char));
	printf("%s\n", ft_itoa(987654321));
	printf("%s\n", ft_itoa(-123456789));
	free(str);
}
*/