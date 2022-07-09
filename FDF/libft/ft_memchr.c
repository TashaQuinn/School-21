/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbania <jbania@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:53:51 by jbania            #+#    #+#             */
/*   Updated: 2022/07/07 00:53:53 by jbania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*string;
	unsigned char	chr;

	i = 0;
	string = (unsigned char *) str;
	chr = (unsigned char) c;
	while (i < n)
	{
		if (string[i] == chr)
			return ((void *)&string[i]);
		i++;
	}
	return (0);
}
