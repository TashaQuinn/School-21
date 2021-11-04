/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbania <jbania@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 22:24:17 by jbania            #+#    #+#             */
/*   Updated: 2021/10/24 23:05:46 by jbania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	to_find_len;
	char	*s;

	i = 0;
	s = (char *)str;
	to_find_len = ft_strlen(to_find);
	if (to_find_len == 0 || str == to_find)
		return (s);
	while (s[i] && i < len)
	{
		j = 0;
		while (s[i + j] && to_find[j] && s[i + j] == to_find[j] && i + j < len)
			j++;
		if (j == to_find_len)
			return (&s[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

 #ifndef HAVE_STRNSTR
 char *strnstr(const char *s, const char *find, size_t slen) {
     char c, sc;
     size_t len;
  
     if ((c = *find++) != '\0') {
     len = strlen(find);
     do {
         do {
         if (slen < 1 || (sc = *s) == '\0')
             return (0);
         --slen;
         ++s;
         } while (sc != c);
         if (len > slen)
         return (0);
     } while (strncmp(s, find, len) != 0);
     s--;
     }
     return ( (char*) s);
 }
 #endif


int main(void) 
{
     const char *largestring = "Foo Bar Baz";
     const char *smallstring = "Bar";
     char *ptr;

     ptr = ft_strnstr(largestring, smallstring, 11);
     printf("%s\n", ptr);
     return 0;
}
*/
/*
The strnstr() function locates the first occurrence of the  
null-terminated string little in the string big, where not 
more than len characters are searched. Characters that appear 
after a `\0' character are not searched.

If little is an empty string, big is returned; if little 
occurs nowhere in big, NULL is returned; otherwise a 
pointer to the first character of the first occurrence 
of little is returned.
*/