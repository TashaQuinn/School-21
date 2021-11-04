/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbania <jbania@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 22:30:03 by jbania            #+#    #+#             */
/*   Updated: 2021/10/24 23:02:47 by jbania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	ch;

	str = (unsigned char *)arr;
	ch = (unsigned char)c;
	i = 0;
	while (n > i)
	{	
		if (str[i] == ch)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>
int main(void)
{
    char str[] = "ABCDEKFG";
    char *ps = memchr(str,'K',strlen(str));
    if (ps != NULL)
       printf ("search character found: %s\n", ps);
    else
       printf ("search character not found\n");
    return 0;
}
*/
/*
Функция memchr ищет вхождение в массив (область памяти) символа, 
код которого задан аргументом c, сравнивая каждый байт массива (области памяти)
определенный как unsigned char с кодом искомого символа. Если искомый символ 
найден, то возвращается адрес найденного символа и сравнение завершается. Если, 
сле проверки n байтов, искомый символ не найден, то сравнение прекращается и 
функция возвращает NULL.
*/