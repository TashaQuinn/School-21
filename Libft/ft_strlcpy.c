/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbania <jbania@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 22:25:58 by jbania            #+#    #+#             */
/*   Updated: 2021/10/24 22:44:35 by jbania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	while (src[i])
		i++;
	src_len = i;
	if (!size)
		return (src_len);
	if (size != 0)
	{
		i = 0;
		while (size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
			size--;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

/*
#include <stdio.h>
#include <string.h>

#ifndef HAVE_STRLCPY
size_t strlcpy(char * dst, const char * src, size_t maxlen) {
    const size_t srclen = strlen(src);
    if (srclen + 1 < maxlen) {
        memcpy(dst, src, srclen + 1);
    } else if (maxlen != 0) {
        memcpy(dst, src, maxlen - 1);
        dst[maxlen-1] = '\0';
    }
    return srclen;
}
#endif

int 	main(void)
{
	char	s[] = {"Fuck.Fuck.Fuck."};
	char	d[22];
	char	sr[] = {"Fuck.Fuck.Fuck."};
	char	ds[22];

	strlcpy(d, s, 0);
	ft_strlcpy(ds, sr, 0);

	printf("%s\n", d);
	printf("%s\n", ds);
	return (0);
}
*/
/*
Функция strlcpy копирует из строки src в буфер dst не более чем
size - 1 символов и гарантированно устанавливает в конец строки
нулевой символ. 

strlcpy() and strlcat() take the full size of the buffer
(not just the length) and guarantee to NUL-terminate the result
(as long as size is larger than 0 or, n the case of strlcat(),
as long as there is at least one byte free in dst).

strlcpy возвращает размер строки по адресу src.

В случае, когда dst указывает на нуль-символ, поведение функций
эквивалентно. строка с null-концом-это строка, в которой символ 
null '\0' отмечает конец строки (не обязательно конец массива). 
Все строки в коде (разделенные двойными кавычками "" ) автоматически
завершаются компилятором null.
*/