#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	if (!(new_elem))
		return (NULL);
	new_elem->content = content;
	new_elem->next = NULL;
	return (new_elem);
}

/*
#include <stdio.h>

int		main(void)
{
    char	str[] = "lorem ipsum dolor sit";
    
    t_list	*elem;
    
    elem = ft_lstnew((void *)str);
    printf("\n%s\n", elem->content);
}
*/