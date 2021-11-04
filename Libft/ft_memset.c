/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbania <jbania@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 22:17:13 by jbania            #+#    #+#             */
/*   Updated: 2021/10/24 22:43:32 by jbania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*s;

	s = (char *)str;
	while (n > 0)
	{
		s[n - 1] = c;
		n--;
	}
	return (str);
}

/*
#include <stdio.h>
#include <string.h>
int main (void)
{
   unsigned char src[15]="1234567890";
 
   ft_memset (src, '1', 10);

   printf("%s\n",src);

   return 0;
}
*/
/*
Функция возвращает указатель на заполняемый массив.

Функция memset заполняет первые n байт области памяти, на которую 
указывает аргумент destination, символом, код которого указывается 
аргументом c.

void has no size, and the [] operator needs a concrete data 
type to operate in a defined manner.
*/