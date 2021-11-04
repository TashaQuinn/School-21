/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbania <jbania@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 22:17:01 by jbania            #+#    #+#             */
/*   Updated: 2021/10/31 15:08:15 by jbania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*s;
	char	*d;

	d = (char *)dst;
	s = (char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

/*
#include <stdio.h>
#include <string.h>

int main (void)
{
   unsigned char src[10]="123456";
   unsigned char dst[10]="";

   memcpy (dst, src, 6);

   printf ("dst: %s\n",dst);

   return 0;
}
*/
/*
Функция возвращает указатель на массив, в который скопированы данные.

Функция memcpy копирует n байт из массива (области памяти), на который 
указывает аргумент source, в массив (область памяти), на который 
указывает аргумент destination. Если массивы перекрываются, результат 
копирования будет не определен.
*/