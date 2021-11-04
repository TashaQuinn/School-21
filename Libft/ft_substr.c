/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbania <jbania@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 22:26:38 by jbania            #+#    #+#             */
/*   Updated: 2021/10/25 12:12:48 by jbania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*res;

	i = 0;
	if (!(s))
		return (NULL);
	if ((start >= ft_strlen(s)) || (len == 0))
		return (ft_calloc(1, sizeof(char)));
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!(res))
		return (NULL);
	while (i < len)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}

/*
#include <string.h>
#include <stdio.h>
int main()
{
    char dest[40] = "Hello my friend";
    printf("%s\n", ft_substr(dest, 6, 9));
}
*/
/*
Функция ft_strsub распределяет (с помощью malloc) и возвращает «свежую» 
подстроку из строки, заданной в качестве аргумента. Подстрока начинается 
с start и имеет размер len. Если start и len не ссылаются на допустимую 
подстроку, поведение не определено. Если распределение завершается неудачно, 
функция возвращает NULL.
Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.
Функция calloc() возвращает указатель на первый байт выделенной области. 
Если памяти недостаточно для удовлетворения запроса, то возвращается 
нулевой указатель. Всегда важно проврять возвращаемое значение на его 
равенство NULL, прежде чем использовать этот указатель.
*/