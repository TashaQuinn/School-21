#include "fdf.h"

int	keys(int key, t_fdf **fdf)
{
	int	i;

	i = 0;
	if (key == KEY_ESC)
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
