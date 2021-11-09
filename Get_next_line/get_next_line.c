/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbania <jbania@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:20:08 by jbania            #+#    #+#             */
/*   Updated: 2021/11/09 12:41:37 by jbania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
Функция strchr выполняет поиск первого вхождения символа symbol в строку 
string. Возвращает указатель на первое вхождение символа в строке. 
Завершающий нулевой символ считается частью Си-строки. Таким образом, он 
также может быть найден для получения указателя на конец строки.
*/
char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if ((unsigned char)*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	if (c == 0)
		return ((char *)str);
	return (NULL);
}

char *ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*dest;
	unsigned int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	dest = (char*)malloc(sizeof(*dest) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	while (*s1 != '\0')
		dest[i++] = *s1++;
	while (*s2 != '\0')
		dest[i++] = *s2++;
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	while (src[len])
		len++;
	str = (char*)malloc(sizeof(*str) * (len + 1));
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}

#include <stddef.h>
char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (!(str))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

void	ft_strclr(char *s)
{
	if (s)
		while (*s)
			*s++ = '\0';
}

/*
char	*check_remainer(char *remainer, char *current_line)
{
	char	*ptr_to_newline_symbol; 

	ptr_to_newline_symbol = NULL;
	if (remainer)
		if ((ptr_to_newline_symbol = ft_strchr(remainer, '\n')))
		{
			*ptr_to_newline_symbol = '\0';
			current_line = ft_strdup(remainer);
			ft_strcpy(remainer, ++ptr_to_newline_symbol);
		}
		else
		{
			current_line = ft_strdup(remainer);
			ft_strclr(remainer);
		}
	else
		current_line = ft_strnew(1);
	return (ptr_to_newline_symbol);
}
*/

char *get_next_line(int fd)
{
    static char *remainer; 
    char        buffer[BUFFER_SIZE + 1];
	char        *current_line;
	int         num_of_symbols_was_read;
	char		*ptr_to_newline_symbol;
	//char		*tmp;
	int			flag;

 	if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
	//ptr_to_newline_symbol = check_remainer(remainer, current_line);
	ptr_to_newline_symbol = NULL;
	if (remainer)
	{
		current_line = ft_strdup(remainer);
	}
	else
	{
		current_line = ft_strnew(1);
	}
	flag = 1;
    while (((flag) && (num_of_symbols_was_read = read(fd, buffer, BUFFER_SIZE))))
	{
		buffer[num_of_symbols_was_read] = '\0';
		if ((ptr_to_newline_symbol = ft_strchr(buffer, '\n')))
		{
			*ptr_to_newline_symbol = '\0';
			remainer = ft_strdup(++ptr_to_newline_symbol);
			flag = 0;
		}
		//tmp = current_line;
		current_line = ft_strjoin(current_line, buffer);
		//free(tmp);
	}
	return (current_line);
}

#include <stdio.h>
int	main(void)
{
	int		fd;
	char	*current_line;

	fd = open("text.txt", O_RDONLY);
	// while ((current_line = get_next_line(fd)) > 0)
	// 	{
	// 		printf("%s", current_line);
	// 		free(current_line);
	// 	}
	current_line = get_next_line(fd);
	printf("%s\n\n", current_line);

	current_line = get_next_line(fd);
	printf("%s\n\n", current_line);

	current_line = get_next_line(fd);
	printf("%s\n\n", current_line);
	return (0);
}