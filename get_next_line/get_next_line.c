/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbania <jbania@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 17:53:42 by jbania            #+#    #+#             */
/*   Updated: 2021/12/25 19:29:47 by jbania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_is_n(char c)
{
	if (c == '\n')
		return (1);
	return (0);
}

int	ft_check_for_n(char *leftovers)
{
	int	i;

	i = 0;
	if (!leftovers)
		return (0);
	while (leftovers[i])
	{
		if (leftovers[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_line(char *leftovers)
{
	int		i;
	char	*line;

	i = 0;
	if (!leftovers || !leftovers[0])
		return (NULL);
	while (leftovers[i] && leftovers[i] != '\n')
		i++;
	i += ft_is_n(leftovers[i]);
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (leftovers[i] && leftovers[i] != '\n')
	{
		line[i] = leftovers[i];
		i++;
	}
	if (leftovers[i] == '\n')
	{
		line[i] = leftovers[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_after_n(char *leftovers)
{
	int		i;
	int		j;
	char	*after_newline;

	i = 0;
	j = 0;
	if (leftovers == NULL)
		return (NULL);
	while (leftovers[i] && leftovers[i] != '\n')
		i++;
	if (leftovers[i] == '\0')
		return (ft_free(leftovers));
	i += ft_is_n(leftovers[i]);
	after_newline = malloc(ft_strlen(leftovers) - i + 1);
	if (!after_newline)
		return (NULL);
	while (leftovers[i])
		after_newline[j++] = leftovers[i++];
	after_newline[j] = '\0';
	free(leftovers);
	leftovers = NULL;
	return (after_newline);
}

char	*get_next_line(int fd)
{
	static char	*leftovers;
	char		*buf;
	char		*line;
	int			bytes_read;

	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!ft_check_for_n(leftovers) && bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_free(buf));
		buf[bytes_read] = '\0';
		leftovers = ft_strjoin(leftovers, buf);
	}
	free(buf);
	line = ft_line(leftovers);
	leftovers = ft_after_n(leftovers);
	return (line);
}
