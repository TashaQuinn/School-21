#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	ch;

	str = (unsigned char *)arr;
	ch = (unsigned char)c;
	i = 0;
	while (n > i)
	{	
		if (str[i] == ch)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>
int main(void)
{
    char str[] = "ABCDEKFG";
    char *ps = memchr(str,'K',strlen(str));
    if (ps != NULL)
       printf ("search character found: %s\n", ps);
    else
       printf ("search character not found\n");
    return 0;
}
*/