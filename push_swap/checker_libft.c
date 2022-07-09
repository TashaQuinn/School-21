#include "push_swap.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] != '\0' && str1[i] == str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

char	*get_next_line(int fd)
{
	int		i;
	int		rd;
	char	*line;

	i = 0;
	rd = 0;
	line = malloc(100000);
	while (1)
	{
		rd = read(fd, &line[i], 1);
		if (rd <= 0 || line[i] == '\n')
			break ;
		i++;
	}
	line[i] = '\0';
	return (line);
}
