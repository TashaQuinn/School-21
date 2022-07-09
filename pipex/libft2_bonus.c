#include "pipex_bonus.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (fd < 0 || !s)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (str1[i] != '\0' && str1[i] == str2[i] && i + 1 < n)
	{
		i++;
	}
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

void	here_doc(t_ppx *ppx, char **argv)
{
	int		fd;
	char	*line;

	fd = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while (1)
	{
		ft_putstr_fd("> ", 1);
		line = get_next_line(0);
		if (ft_strncmp(argv[2], line, ft_strlen(argv[2]) + 1) == 0)
			break ;
		ft_putstr_fd(line, fd);
		ft_putstr_fd("\n", fd);
		free(line);
	}
	free(line);
	close(fd);
	ppx->ifd = open(".heredoc_tmp", O_RDONLY);
	ppx->ofd = open(argv[ppx->argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
}

int	here_var(t_ppx *ppx)
{
	if (ppx->here == 1)
		return (ppx->argc - 4);
	else
		return (ppx->argc - 3);
}
