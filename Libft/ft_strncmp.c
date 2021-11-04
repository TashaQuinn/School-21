#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
#include <string.h>
#include <stdio.h>

void demo(const char* s1, const char* s2, size_t n)
{
    int rc = ft_strncmp(s1, s2, n);
    if(rc == 0)
        printf("First %d chars of [%s] equal [%s]\n", n, s1, s2);
    else if(rc < 0)
        printf("First %d chars of [%s] precede (<) [%s]\n", n, s1, s2);
    else if(rc > 0)
        printf("First %d chars of [%s] follow (>) [%s]\n", n, s1, s2);
 
}
int main(void)
{
    const char* string = "heyz";
    demo(string, "heyn", 4);
    demo(string, "heyz", 10);
    demo(string, "heeey", 10);
    demo(string, "heyz ", 5);
}
*/