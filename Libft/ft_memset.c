#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*s;

	s = (char *)str;
	while (n > 0)
	{
		s[n - 1] = c;
		n--;
	}
	return (str);
}

/*
#include <stdio.h>
#include <string.h>
int main (void)
{
   unsigned char src[15]="1234567890";
 
   ft_memset (src, '1', 10);

   printf("%s\n",src);

   return 0;
}
*/
