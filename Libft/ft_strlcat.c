/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbania <jbania@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 22:27:07 by jbania            #+#    #+#             */
/*   Updated: 2021/10/24 22:44:24 by jbania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(dst) + ft_strlen(src);
	if (size <= ft_strlen(dst))
		return (ft_strlen(src) + size);
	while (*dst)
		dst++;
	i = 0;
	while ((i < size - (len - ft_strlen(src)) - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

/*
#include <string.h>
#include <stdio.h>

void *ft_memcpy (void *dst, const void *src, size_t n)
{
	if (!dst)
		return (NULL);
	while (n--)
		*(char*)(dst++) = *(char*)(src++);
	return (dst);
}

#ifndef HAVE_STRLCAT
size_t strlcat(char * restrict dst, const char * restrict src, size_t maxlen) {
    const size_t srclen = strlen(src);
    const size_t dstlen = strnlen(dst, maxlen);
    if (dstlen == maxlen) return maxlen+srclen;
    if (srclen < maxlen-dstlen) {
        memcpy(dst+dstlen, src, srclen+1);
    } else {
        memcpy(dst+dstlen, src, maxlen-1);
        dst[dstlen+maxlen-1] = '\0';
    }
    return dstlen + srclen;
}
#endif


int 	main(void)
{
	char	s[] = {"123456"};
	char	d[16] = {"lol.haha"}; //8
	char	sr[] = {"123456"};
	char	ds[16] = {"lol.haha"}; //8

	strlcat(d, s, 10);
	ft_strlcat(ds, sr, 10);

	printf("%s\n", d);
	printf("%s\n", ds);
	return (0);
}
*/
/*
strlcat делает то же самое, однако копирование ведётся не в начало dst, 
а таким образом, чтобы продолжить строку, на которую указывает dst. 

strlcpy() and strlcat() take the full size of the buffer 
(not just the length) and guarantee to NUL-terminate the result
(as long as size is larger than 0 or, n the case of strlcat(), as
long as there is at least one byte free in dst).

strlcat возвращает суммарную длину строк по адресам src и dst. 
Возвращаемое значение не зависит от того, удалось скопировать строку 
полностью или нет; это позволяет легко определить что буфер
назначения слишком мал для копируемой строки.

В случае, когда dst указывает на нуль-символ, поведение функций
эквивалентно.
*/