/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbania <jbania@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:55:09 by jbania            #+#    #+#             */
/*   Updated: 2022/07/07 00:55:11 by jbania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_free(char *str)
{
	free(str);
	return (0);
}

size_t	ft_gnlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
	{
		return (0);
	}
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_gnl_strjoin(char const *s1, char const *s2)
{
	char	*string;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	j = 0;
	string = (char *)malloc(sizeof(char) * (ft_gnlen(s1) + ft_gnlen(s2) + 1));
	if (!string)
		return (0);
	while (s1 && s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		string[i] = s2[j];
		i++;
		j++;
	}
	string[i] = '\0';
	free((void *)s1);
	return (string);
}
