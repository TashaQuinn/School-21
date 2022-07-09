#include "fdf.h"

void	connect_dots(t_fdf dot1, t_fdf dot2, t_fdf *fdf)
{
	float	x_step;
	float	y_step;
	float	maxm;

	set_params(&dot1, &dot2, fdf);
	x_step = dot2.x - dot1.x;
	y_step = dot2.y - dot1.y;
	is_max(&x_step, &y_step, &maxm);
	x_step /= ft_abs(maxm);
	y_step /= ft_abs(maxm);
	if ((dot2.z || dot1.z) && (dot1.hex_color == 0 && dot2.hex_color == 0))
		dot1.color = 0x0057b7;
	else if ((dot1.hex_color == 0 && dot2.hex_color == 0)
		&& (!dot1.z && !dot2.z))
		dot1.color = 0xffd700;
	while ((int)(dot1.x - dot2.x) || (int)(dot1.y - dot2.y))
	{
		draw_pixel(dot1, fdf);
		dot1.x += x_step;
		dot1.y += y_step;
		if (dot1.x > 1200 || dot1.y > 800 || dot1.x < 0 || dot1.y < 0)
			break ;
	}
}

void	draw(t_fdf **fdf)
{
	int	x;
	int	y;

	fdf[0][0].img = mlx_new_image(fdf[0][0].mlx_ptr, 1200, 800);
	fdf[0][0].addr = mlx_get_data_addr(fdf[0][0].img,
			&fdf[0][0].bpp, &fdf[0][0].bline, &fdf[0][0].endian);
	y = 0;
	while (fdf[y])
	{
		x = 0;
		while (1)
		{
			if (fdf[y + 1])
				connect_dots(fdf[y][x], fdf[y + 1][x], &(fdf[0][0]));
			if (!fdf[y][x].last)
				connect_dots(fdf[y][x], fdf[y][x + 1], &(fdf[0][0]));
			if (fdf[y][x].last)
				break ;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf[0][0].mlx_ptr,
		fdf[0][0].win_ptr, fdf[0][0].img, 0, 0);
	mlx_destroy_image(fdf[0][0].mlx_ptr, fdf[0][0].img);
}

void	init_fdf(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1200, 800, "FDF");
	fdf->zoom = 14;
	fdf->shift_x = 400;
	fdf->shift_y = 250;
	fdf->hex_color = 0;
	fdf->rad = 0.0;
}

int	close_fdf(t_fdf **fdf)
{
	int	i;

	i = 0;
	mlx_destroy_image(fdf[0][0].mlx_ptr, fdf[0][0].win_ptr);
	while (fdf[i])
		free(fdf[i++]);
	free(fdf);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_fdf	**fdf;

	input_check(argc, argv);
	fdf = parse_map(argv[1]);
	init_fdf(&(fdf[0][0]));
	draw(fdf);
	mlx_key_hook(fdf[0][0].win_ptr, keys, fdf);
	mlx_hook(fdf[0][0].win_ptr, 17, 0, close_fdf, fdf);
	mlx_loop(fdf[0][0].mlx_ptr);
	return (0);
}
