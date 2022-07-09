#include "fdf_bonus.h"

t_fdf	**malloc_fdf(char *file_name)
{
	t_fdf	**fdf;
	int		x;
	int		y;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	x = ft_cnt_words(line, ' ');
	free(line);
	y = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		y++;
		free(line);
	}
	free(line);
	fdf = (t_fdf **)malloc(sizeof(t_fdf *) * (y + 1));
	while (y > 0)
		fdf[--y] = (t_fdf *)malloc(sizeof(t_fdf) * (x + 1));
	close(fd);
	return (fdf);
}

int	hex_to_dec(char *hex)
{
	int		nb;
	int		len;
	int		base;
	int		decimal;
	char	*ptr;

	ptr = ft_strchr(hex, ',');
	ptr++;
	len = ft_strlen(ptr) - 1;
	base = 1;
	decimal = 0;
	while (len >= 0)
	{
		if (ft_isdigit(ptr[len]))
			nb = ptr[len] - '0';
		else
			nb = ft_toupper(ptr[len]) - 'A' + 10;
		decimal += nb * base;
		base *= 16;
		len--;
	}
	return (decimal);
}

int	line_to_fdf(char *line, t_fdf **fdf, int y)
{
	char	**zs;
	int		x;

	zs = ft_split(line, ' ');
	x = 0;
	while (zs[x])
	{
		fdf[y][x].z = ft_atoi(zs[x]);
		fdf[y][x].x = x;
		fdf[y][x].y = y;
		fdf[y][x].last = 0;
		if (ft_strchr(zs[x], ','))
		{
			fdf[y][x].color = hex_to_dec(zs[x]);
			fdf[y][x].hex_color = 1;
		}
		else
			fdf[y][x].color = 0x0057b7;
		free(zs[x++]);
	}
	free(zs);
	free(line);
	fdf[y][--x].last = 1;
	return (x);
}

t_fdf	**parse_map(char *file_name)
{
	t_fdf	**fdf;
	int		y;
	int		fd;
	char	*line;

	fdf = malloc_fdf(file_name);
	fd = open(file_name, O_RDONLY);
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line_to_fdf(line, fdf, y++);
	}
	free(line);
	fdf[y] = NULL;
	close(fd);
	return (fdf);
}
