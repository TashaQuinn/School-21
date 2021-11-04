#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char		*s;
	char		find;
	size_t		i;

	s = (char *)str;
	find = (char)c;
	i = ft_strlen(str);
	while (i > 0)
	{
		if (s[i] == find)
			return (&s[i]);
		i--;
	}
	if (s[i] == find)
		return (s);
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
int main () {
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = '.';
   char *ret;

   ret =  ft_strrchr(str, ch);

   printf("String after |%c| is - |%s|\n", ch, ret);
   
   return(0);
}
*/