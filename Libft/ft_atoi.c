/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbania <jbania@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:26:47 by oem               #+#    #+#             */
/*   Updated: 2021/11/02 11:02:13 by jbania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int						i;
	unsigned long long int	result;
	int						minus;

	minus = 1;
	result = 0;
	i = ft_isspace(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] >= '0' && '9' >= str[i])
		result = result * 10 + (str[i++] - '0');
	if (i > 19 || result >= 9223372036854775808ULL)
	{
		if (minus == 1)
			return (-1);
		else
			return (0);
	}
	return (result * minus);
}

/*
#include <stdio.h>
int main()
{
	char numbers1[] = {"    -+---+1232a34"};
	char numbers2[] = {" -1232a34"};
	char numbers3[] = {"-9223372036854775808"};
	char numbers4[] = {"+92233720368547758007"};
	char numbers5[] = {"-99999999999999999999999999"};
	char numbers6[] = {"99999999999999999999999999"};

	printf("%s", " 1:");
	printf("%d\n 1:", ft_atoi(numbers1));
	printf("%d\n 2:", atoi(numbers1));
	printf("%d\n 2:", ft_atoi(numbers2));
	printf("%d\n 3:", atoi(numbers2));
	printf("%d\n 3:", ft_atoi(numbers3));
	printf("%d\n 4:", atoi(numbers3));
	printf("%d\n 4:", ft_atoi(numbers4));
	printf("%d\n 5:", atoi(numbers4));
	printf("%d\n 5:", ft_atoi(numbers5));
	printf("%d\n 6:", atoi(numbers5));
	printf("%d\n 6:", ft_atoi(numbers6));
	printf("%d\n", atoi(numbers6));
	return(0);
}
*/
