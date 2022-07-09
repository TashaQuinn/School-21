/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbania <jbania@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:55:37 by jbania            #+#    #+#             */
/*   Updated: 2022/07/07 00:55:40 by jbania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*str1, const char *str2, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		length;
	char		*string;

	string = (char *) str1;
	i = 0;
	j = 0;
	length = ft_strlen(str2);
	if (length == 0)
		return (string);
	while (string[i] != '\0')
	{
		if (string[i] == str2[j])
		{
			while (string[i + j] == str2[j] && j < length && j + i < len)
				j++;
			if (j == length)
				return (&string[i]);
		}
		i++;
		j = 0;
	}
	return (0);
}
