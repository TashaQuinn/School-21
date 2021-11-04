/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbania <jbania@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 22:28:28 by jbania            #+#    #+#             */
/*   Updated: 2021/10/24 20:47:20 by jbania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*buf;

	if (s == NULL || !f)
		return (NULL);
	buf = (char *)malloc(sizeof(*buf) * (ft_strlen(s) + 1));
	if (buf == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		buf[i] = f(i, s[i]);
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

/*
#include <stdio.h>
#include <string.h>

char f(unsigned int i, char ch)
{
	char s;

	s = ch + i;
	return (s);
}

int main()
{
	char str1[] = {"abc"};
	char* str2;
	str2 = ft_strmapi(str1, &f);
	printf("%s\n", str2);
}
*/
/*
Applies the function ’f’ to each character of the
string ’s’ to create a new string (with malloc(3))
resulting from successive applications of ’f’.
Return value: The string created from the successive applications
of ’f’. Returns NULL if the allocation fails.
*/