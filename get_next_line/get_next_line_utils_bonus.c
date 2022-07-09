
#include "get_next_line_bonus.h"

char	*ft_free(char *str)
{
	free(str);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
	{
		return (0);
	}
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	j = 0;
	string = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!string)
		return (0);
	while (s1 && s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		string[i] = s2[j];
		i++;
		j++;
	}
	string[i] = '\0';
	free((void *)s1);
	return (string);
}
