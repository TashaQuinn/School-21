/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbania <jbania@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:55:42 by jbania            #+#    #+#             */
/*   Updated: 2022/07/07 00:55:44 by jbania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_check_set(char c, char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*string;
	char	*copy;

	start = 0;
	i = 0;
	string = (char *)s1;
	end = ft_strlen(string);
	while ((ft_check_set(string[start], (char *)set) == 1) && start < end)
		start++;
	while ((ft_check_set(string[end - 1], (char *)set) == 1) && end > start)
		end--;
	copy = (char *)malloc(sizeof(*copy) * (end - start + 1));
	if (!copy)
		return (0);
	while (i < end - start)
	{
		copy[i] = string[start + i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
