#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*s;
	char	*copy;
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	s = (char *)malloc(sizeof(*str) * (len + 1));
	if (!(s))
		return (NULL);
	copy = s;
	while (*str)
	{
		*copy++ = *str++;
	}
	*copy = '\0';
	return (s);
}

/*
#include <stdio.h>
int     main(int argc, char **argv)
{
	char *dup;
	
	if (argc == 2)	
	{
		dup = ft_strdup(argv[1]);
		printf("%s", dup);
		free(dup);
	}
	return (0);	
}
*/