#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	unsigned char	*a1;
	unsigned char	*a2;
	size_t			i;

	if (n == 0)
		return (0);
	a1 = (unsigned char *)arr1;
	a2 = (unsigned char *)arr2;
	i = 1;
	while (*a1 == *a2 && i < n)
	{
		a1++;
		a2++;
		i++;
	}
	return ((int)(*a1 - *a2));
}

/*
#include <stdio.h>
#include <string.h>

int main( void )
{
   char first[]  = "12345678901234567890";
   char second[] = "12345678901234567891";
   int int_arr1[] = {1,2,3,4};
   int int_arr2[] = {1,2,3,4};
   int result;

   printf( "Compare '%.21s' to '%.21s':\n", first, second );
   result = ft_memcmp( first, second, 21 );
   if( result < 0 )
      printf( "First is less than second.\n" );
   else if( result == 0 )
      printf( "First is equal to second.\n" );
   else
      printf( "First is greater than second.\n" );

   printf( "Compare '%d,%d' to '%d,%d':\n", int_arr1[0], int_arr1[1],
  int_arr2[0], int_arr2[1]);
   result = ft_memcmp( int_arr1, int_arr2, sizeof(int) * 2 );
   if( result < 0 )
      printf( "int_arr1 is less than int_arr2.\n" );
   else if( result == 0 )
      printf( "int_arr1 is equal to int_arr2.\n" );
   else
      printf( "int_arr1 is greater than int_arr2.\n" );
}
*/