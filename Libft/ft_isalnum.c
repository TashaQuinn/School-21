#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

/*
#include <stdio.h>
#include <ctype.h>
int main()
{
    char c;

    printf("Enter a character: ");
    scanf("%c", &c);

    if (ft_isalnum(c) == 0)
         printf("%c is neither an alphabet or number.", c);
    else
         printf("%c is an alphabet or a number.", c);

    return (0);
}
*/