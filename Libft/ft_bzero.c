/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbania <jbania@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 22:15:19 by jbania            #+#    #+#             */
/*   Updated: 2021/11/02 11:02:02 by jbania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

/*
#include <strings.h>
#include <stdio.h>
int main( void )
  {
    char buffer[80];

    ft_bzero (buffer, 80);
	bzero (buffer, 80);
    return (0);
  }
*/
/*
Функция bzero() устанавливает первые n байтов области, 
начинающейся с s в нули (пустые байты).  
*/