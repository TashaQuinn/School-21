/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbania <jbania@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 09:21:55 by jbania            #+#    #+#             */
/*   Updated: 2021/11/07 09:38:33 by jbania           ###   ########.fr       */
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