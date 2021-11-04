/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbania <jbania@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 20:30:23 by jbania            #+#    #+#             */
/*   Updated: 2021/11/03 20:42:46 by jbania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	int		i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

void	ft_free_memory(char **memory)
{
	int	i;

	i = 0;
	while (memory[i])
	{
		free(memory[i]);
		i++;
	}
	free(memory);
}

size_t	ft_word_len(const char *str, char c)
{
	int	i;

	i = 0;
	while (*str == c)
		str++;
	while (*str && *str != c)
	{
		i++;
		str++;
	}
	return (i);
}

char	**ft_pre_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**str;

	if (!s)
		return (NULL);
	i = ft_count_words(s, c);
	str = ft_calloc(i + 1, sizeof(char *));
	if (str == NULL)
		return (NULL);
	j = 0;
	while (i > j)
	{
		while (*s == c)
			s++;
		str[j] = ft_substr (s, 0, ft_word_len (s, c));
		if (str[j++] == NULL)
		{
			ft_free_memory(str);
			return (NULL);
		}
		s += ft_word_len (s, c);
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = ft_pre_split (s, c);
	if (!str)
		return (NULL);
	return (str);
}

/*
#include <stdio.h>

int     main(void)
{
	char	**arr_str;
	char c;

	c = ' ';
	if ((arr_str = ft_split("", c)) == ((void *)0))
	{
		free(arr_str);
		return (0);
	}
	while (*arr_str != ((void *)0))	
	{
		printf("%s\n", *arr_str);
		arr_str++;
	}
	free(arr_str);
	return (0);
}
*/
/*
void	*ft_calloc(size_t number, size_t size)
Функция calloc() возвращает указатель на выделенную память. Размер выделенной 
памяти равен величине num*size, где size задается в байтах. Это означает, 
что функция calloc() выделяет достаточно памяти для массива из num объектов 
каждый размером size байт.

char	*ft_substr(char const *s, unsigned int start, size_t len)
Функция ft_strsub распределяет (с помощью malloc) и возвращает «свежую» 
подстроку из строки, заданной в качестве аргумента. Подстрока начинается 
с start и имеет размер len. Если start и len не ссылаются на допустимую 
подстроку, поведение не определено. Если распределение завершается неудачно, 
функция возвращает NULL.
*/