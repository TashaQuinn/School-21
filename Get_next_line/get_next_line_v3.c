#include "get_next_line.h"

char	*ft_free(char *str)
{
	free(str);
	return (0);
}

int	ft_is_newline(char *str)
{
	if (str[0] == '\n')
		return (1);
	return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*newstr;
	unsigned int	bytes;
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (0);
	bytes = (ft_strlen(s1) + ft_strlen(s2) + 1);
	newstr = malloc(sizeof(char) * bytes);
	if (!newstr)
		return (0);
	while (s1 != NULL && s1[j])
		newstr[i++] = s1[j++];
	j = 0;
	while (s2 != NULL && s2[j])
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	free((void *)s1);
	s1 = NULL;
	return (newstr);
}

int	ft_scan_newline(char *remainer)
{
	int	i;

	i = 0;
	if (!remainer)
		return (0);
	while (remainer[i])
	{
		if (remainer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_fill_theline(char *remainer)
{
	int		i;
	char	*filled_line;

	i = 0;
	if (!remainer || !remainer[0])
		return (NULL);
	while (remainer[i] && remainer[i] != '\n')
		i++;
	i += ft_is_newline(&remainer[i]);
	filled_line = malloc(sizeof(char) * (i + 1));
	if (!filled_line)
		return (0);
	i = 0;
	while (remainer[i] && remainer[i] != '\n')
	{
		filled_line[i] = remainer[i];
		i++;
	}
	if (remainer[i] == '\n')
	{
		filled_line[i] = remainer[i];
		i++;
	}
	filled_line[i] = '\0';
	return (filled_line);
}

char	*ft_after_newline(char *remainer)
{
	int		i;
	int		j;
	char	*after_newline;

	i = 0;
	j = 0;
	if (remainer == NULL)
		return (NULL);
	while (remainer[i] && remainer[i] != '\n')
		i++;
	if (remainer[i] == '\0')
		return (ft_free(remainer));
	i += ft_is_newline(&remainer[i]);
	after_newline = malloc(sizeof(char) * (ft_strlen(remainer) - i + 1));
	if (!after_newline)
		return (0);
	while (remainer[i])
		after_newline[j++] = remainer[i++];
	after_newline[j] = '\0';
	free(remainer);
	remainer = NULL;
	return (after_newline);
}

char	*get_next_line(int fd)
{
	static char	*remainer[1024];
	char		*buffer;
	char		*line;
	int			return_value;

	return_value = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_scan_newline(remainer[fd]) && return_value != 0)
	{
		return_value = read(fd, buffer, BUFFER_SIZE);
		if (return_value == -1)
			return (ft_free(buffer));
		buffer[return_value] = '\0';
		remainer[fd] = ft_strjoin(remainer[fd], buffer);
	}
	free(buffer);
	line = ft_fill_theline(remainer[fd]);
	remainer[fd] = ft_after_newline(remainer[fd]);
	return (line);
}

#include <stdio.h>
int	main(void)
{
	int		fd;
	char	*current_line;

	fd = open("text.txt", O_RDONLY);
	current_line = get_next_line(fd);
	printf("%s\n\n", current_line);

	current_line = get_next_line(fd);
	printf("%s\n\n", current_line);

	current_line = get_next_line(fd);
	printf("%s\n\n", current_line);
	return (0);
}