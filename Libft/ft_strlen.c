/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbania <jbania@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 22:25:44 by jbania            #+#    #+#             */
/*   Updated: 2021/10/23 20:03:51 by jbania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
    char a[20]="Program";
    char b[20]={'P','r','o','g','r','a','m','\0'};
    char c[20]="\0";

    printf("Length of string a = %ld \n",strlen(a));
    printf("Length of string a = %ld \n",ft_strlen(a));
    
    printf("Length of string b = %ld \n",strlen(b));
    printf("Length of string b = %ld \n",ft_strlen(b));

    printf("Length of string c = %ld \n",strlen(c));
    printf("Length of string c = %ld \n",ft_strlen(c));

    return 0;
}
*/