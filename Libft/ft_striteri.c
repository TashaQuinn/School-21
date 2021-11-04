#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
#include <stdio.h>
#include <unistd.h>

void f(unsigned int i, char *s)
{
	printf("%s\n", s);
}

int main()
{
	char str1[] = "hey";
	
	ft_striteri(str1, &f);
}
*/