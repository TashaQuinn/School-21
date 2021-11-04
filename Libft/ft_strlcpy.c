#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	while (src[i])
		i++;
	src_len = i;
	if (!size)
		return (src_len);
	if (size != 0)
	{
		i = 0;
		while (size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
			size--;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

/*
#include <stdio.h>
#include <string.h>

#ifndef HAVE_STRLCPY
size_t strlcpy(char * dst, const char * src, size_t maxlen) {
    const size_t srclen = strlen(src);
    if (srclen + 1 < maxlen) {
        memcpy(dst, src, srclen + 1);
    } else if (maxlen != 0) {
        memcpy(dst, src, maxlen - 1);
        dst[maxlen-1] = '\0';
    }
    return srclen;
}
#endif

int 	main(void)
{
	char	s[] = {"Fuck.Fuck.Fuck."};
	char	d[22];
	char	sr[] = {"Fuck.Fuck.Fuck."};
	char	ds[22];

	strlcpy(d, s, 0);
	ft_strlcpy(ds, sr, 0);

	printf("%s\n", d);
	printf("%s\n", ds);
	return (0);
}
*/