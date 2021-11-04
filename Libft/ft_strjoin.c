/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbania <jbania@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 22:26:16 by jbania            #+#    #+#             */
/*   Updated: 2021/10/31 15:32:11 by jbania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!(res))
		return (NULL);
	ft_memcpy(res, s1, ft_strlen(s1));
	ft_memcpy(res + ft_strlen(s1), s2, ft_strlen(s2));
	res[(ft_strlen(s1)) + (ft_strlen(s2))] = '\0';
	return (res);
}

/*
#include <string.h>
#include <stdio.h>
int 	main(void)
{
	char	str1[] = {"I love "}; //7
	char	str2[] = {"cats."}; //5

	printf("%s\n", ft_strjoin(str1, str2));
	return (0);
}
*/