#include <stdio.h>
#include "libftprintf.h"

int main()
{
    void *ptr_nill;
    void *ptr = "Hello world!";
    char *str = NULL;

    printf("c printf: %c\n", 'H');
    ft_printf("c ft_printf: %c\n\n", 'i');

    printf("s printf: %s\n", str);
    ft_printf("s ft_printf: %s\n\n", str);

    printf("s printf: %s\n","unsigned int max = 4294967296");
    ft_printf("s ft_printf: %s\n\n","unsigned int max = 4294967296");

    printf("u printf(pos): %u\n",  2147483647);
    ft_printf("u ft_printf(pos): %u\n\n",  2147483647);

    printf("d printf(neg): %d\n", -2147483647);
    ft_printf("d ft_printf(neg): %d\n\n", -2147483647);
    printf("d printf(pos): %d\n", 2147483647);
    ft_printf("d ft_printf(pos): %d\n\n", 2147483647);

    printf("i printf(neg): %i\n", -123);
    ft_printf("i ft_printf(neg): %i\n\n", -123);
    printf("i printf(pos): %i\n", 2147483647);
    ft_printf("i ft_printf(pos): %i\n\n", 2147483647);

    printf("percent printf: %%\n");
    ft_printf("percent ft_printf: %%\n\n");

    printf("ptr(NULL) printf: %p\n", ptr_nill);
    ft_printf("ptr(NULL) ft_printf: %p\n\n", ptr_nill);
    printf("ptr printf: %p\n", ptr);
    ft_printf("ptr ft_printf: %p\n\n", ptr);

    printf("hex printf: %x\n", 112);
    ft_printf("hex ft_printf: %x\n\n", 112);

    return (0);
}
