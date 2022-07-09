#include "fdf_bonus.h"

void	handle_keys(int key, t_fdf **fdf)
{
	if (key == KEY_UP)
		fdf[0][0].shift_y -= 15;
	if (key == KEY_DOWN)
		fdf[0][0].shift_y += 15;
	if (key == KEY_LEFT)
		fdf[0][0].shift_x -= 15;
	if (key == KEY_RIGHT)
		fdf[0][0].shift_x += 15;
	if (key == KEY_PLUS)
		fdf[0][0].zoom += 0.5;
	if (key == KEY_MINUS)
		fdf[0][0].zoom -= 0.5;
	if (key == ROTATE1)
		fdf[0][0].rad += 0.1;
	if (key == ROTATE2)
		fdf[0][0].rad -= 0.1;
	if (key == KEY_THREE)
		fdf[0][0].iso = 1;
	if (key == KEY_TWO)
		fdf[0][0].iso = 0;
}

int	keys(int key, t_fdf **fdf)
{
	int	i;

	i = 0;
	handle_keys(key, fdf);
	if (key == KEY_ESC || key == KEY_Q)
	{
		mlx_destroy_window(fdf[0][0].mlx_ptr, fdf[0][0].win_ptr);
		while (fdf[i])
			free(fdf[i++]);
		free(fdf);
		exit(0);
	}
	draw(fdf);
	return (0);
}
