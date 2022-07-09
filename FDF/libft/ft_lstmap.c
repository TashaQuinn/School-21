/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbania <jbania@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:53:39 by jbania            #+#    #+#             */
/*   Updated: 2022/07/07 00:53:41 by jbania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*link;

	if (!f || !del)
		return (NULL);
	list = NULL;
	while (lst)
	{
		link = ft_lstnew(f(lst->content));
		if (!link)
		{
			ft_lstclear(&link, del);
			return (NULL);
		}
		ft_lstadd_back(&list, link);
		lst = lst->next;
	}
	return (list);
}
