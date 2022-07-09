/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbania <jbania@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:53:07 by jbania            #+#    #+#             */
/*   Updated: 2022/07/07 00:53:09 by jbania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*string;
	size_t	count;
	long	number;

	number = n;
	count = ft_count_digits(n);
	string = (char *)malloc(sizeof(*string) * (count + 1));
	if (!string)
		return (0);
	if (number == 0)
		string[0] = '0';
	if (number < 0)
	{
		string[0] = '-';
		number *= -1;
	}
	string[count--] = '\0';
	while (number != 0)
	{
		string[count] = (number % 10) + '0';
		number /= 10;
		count--;
	}
	return (string);
}
