/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbania <jbania@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:31:28 by jbania            #+#    #+#             */
/*   Updated: 2021/10/24 22:45:04 by jbania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char		*s;
	char		find;
	size_t		i;

	s = (char *)str;
	find = (char)c;
	i = ft_strlen(str);
	while (i > 0)
	{
		if (s[i] == find)
			return (&s[i]);
		i--;
	}
	if (s[i] == find)
		return (s);
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
int main () {
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = '.';
   char *ret;

   ret =  ft_strrchr(str, ch);

   printf("String after |%c| is - |%s|\n", ch, ret);
   
   return(0);
}
*/
/*
Функция ищет последнее вхождение символа symbol в 
строку string. Возвращает указатель на последнее 
вхождение символа в строке string. Завершающий 
нулевой символ считается частью строки. Таким 
образом, он также может быть найден для получения 
указателя на конец строки.

Возвращаемое значение
Указатель на последнее вхождение символа в строку 
string.
Если значение не найдено, функция возвращает 
нулевой указатель.
*/