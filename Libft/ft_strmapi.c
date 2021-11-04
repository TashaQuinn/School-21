#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*buf;

	if (s == NULL || !f)
		return (NULL);
	buf = (char *)malloc(sizeof(*buf) * (ft_strlen(s) + 1));
	if (buf == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		buf[i] = f(i, s[i]);
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

/*
#include <stdio.h>
#include <string.h>

char f(unsigned int i, char ch)
{
	char s;

	s = ch + i;
	return (s);
}

int main()
{
	char str1[] = {"abc"};
	char* str2;
	str2 = ft_strmapi(str1, &f);
	printf("%s\n", str2);
}
*/