/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbania <jbania@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 22:25:28 by jbania            #+#    #+#             */
/*   Updated: 2021/10/24 22:44:00 by jbania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*
#include <stdio.h>
int     main(int argc, char **argv)
{
	char *dup;
	
	if (argc == 2)	
	{
		dup = ft_strdup(argv[1]);
		printf("%s", dup);
		free(dup);
	}
	return (0);	
}
*/
/*
Возвращает указатель на новую строку, являющуюся дубликатом строки s.
Память под новую строку выделятся с помощью malloc(3) и может быть
высвобождены с помощью free(3).

Возвращает указатель на строку-дубль или NULL, если недостаточно памяти.
*/