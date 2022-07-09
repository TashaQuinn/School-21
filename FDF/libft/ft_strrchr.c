/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbania <jbania@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:55:23 by jbania            #+#    #+#             */
/*   Updated: 2022/07/07 00:55:26 by jbania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	len;
	char	*string;
	char	chr;

	string = (char *) str;
	chr = (char) c;
	len = ft_strlen(str);
	while (len > 0)
	{
		if (string[len] == chr)
			return (&string[len]);
		len--;
	}
	if (string[len] == chr)
		return (string);
	return (0);
}
