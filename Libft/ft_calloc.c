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