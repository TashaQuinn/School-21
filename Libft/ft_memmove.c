#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	if (!dst && !src)
		return (NULL);
	if (src < dst)
	{
		while (++i <= n)
			((char *)dst)[n - i] = ((char *)src)[n - i];
	}
	else
	{
		while (n > 0)
		{
			((char *)dst)[j] = ((char *)src)[j];
			j++;
			n--;
		}
	}
	return (dst);
}

/*
#include <stdio.h>
#include <string.h>

int main (void)
{
   unsigned char src[9]="12345678";
   unsigned char dst[8]="";

   memmove (dst, src, 6);

   printf ("dst: %s\n",dst);

   return 0;
}
*/
