/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbania <jbania@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 09:21:55 by jbania            #+#    #+#             */
/*   Updated: 2021/11/07 18:46:14 by jbania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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