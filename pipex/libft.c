#include "pipex.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*string;

	i = 0;
	string = (char *) s;
	while (i < n)
	{
		string[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*res;

	res = malloc(size * n);
	if (!res)
		return (NULL);
	ft_bzero(res, size * n);
	return (res);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*string;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	if (start >= ft_strlen(s) || (len == 0))
		return (ft_calloc(1, sizeof(char)));
	while (i < len && s[(size_t) start + i] != '\0')
		i++;
	string = (char *)malloc(sizeof(*string) * (i + 1));
	if (!string)
		return (0);
	while (i > 0)
	{
		string[j] = s[start];
		j++;
		start++;
		i--;
	}
	string[j] = '\0';
	return (string);
}

char	*ft_strjoin(char const *s1, char c, char const *s2)
{
	char	*string;
	int		len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len = (ft_strlen(s1) + ft_strlen(s2) + 2);
	string = (char *)malloc(sizeof(char) * len);
	if (!string)
		return (0);
	while (i < ft_strlen(s1))
	{
		string[i] = s1[i];
		i++;
	}
	string[i++] = c;
	while (j < ft_strlen(s2))
	{
		string[i++] = s2[j++];
	}
	string[i] = '\0';
	return (string);
}
