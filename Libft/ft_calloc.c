/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbania <jbania@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 22:15:33 by jbania            #+#    #+#             */
/*   Updated: 2021/11/02 11:01:54 by jbania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*memory;

	memory = malloc(number * size);
	if (!(memory))
		return (NULL);
	ft_bzero (memory, (number * size));
	return (memory);
}

/*
#include <strings.h>
#include <stdio.h>
int main( void )
{
   long *buffer;

   buffer = (long *)ft_calloc( 40, sizeof( long ) );
   if( buffer != NULL )
      printf( "Allocated 40 long integers\n" );
   else
      printf( "Can't allocate memory\n" );
   free( buffer );
}
*/
/*
Функция calloc() возвращает указатель на выделенную память. Размер выделенной 
памяти равен величине num*size, где size задается в байтах. Это означает, 
что функция calloc() выделяет достаточно памяти для массива из num объектов 
каждый размером size байт.
Функция calloc() возвращает указатель на первый байт выделенной области. 
Если памяти недостаточно для удовлетворения запроса, то возвращается 
нулевой указатель. Всегда важно проврять возвращаемое значение на его 
равенство NULL, прежде чем использовать этот указатель.
*/