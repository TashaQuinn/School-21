#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*s;
	char	*d;

	d = (char *)dst;
	s = (char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

/*
#include <stdio.h>
#include <string.h>

int main (void)
{
   unsigned char src[10]="123456";
   unsigned char dst[10]="";

   memcpy (dst, src, 6);

   printf ("dst: %s\n",dst);

   return 0;
}
*/
