#include "fdf.h"

void	iso(t_fdf *dot)
{
	int	x_pr;
	int	y_pr;

	x_pr = dot->x;
	y_pr = dot->y;
	dot->x = (x_pr - y_pr) * cos(0.523599);
	dot->y = -dot->z + (x_pr + y_pr) * sin(0.523599);
}

void	rotation(t_fdf *dot, float angle)
{
	float	old_x;
	float	old_y;

	old_x = dot->x;
	old_y = dot->y;
	dot->x = old_x * cos(angle) - old_y * sin(angle);
	dot->y = old_x * sin(angle) + old_y * cos(angle);
}

void	set_params(t_fdf *dot1, t_fdf *dot2, t_fdf *fdf)
{
	dot1->x *= fdf->zoom;
	dot1->y *= fdf->zoom;
	dot2->x *= fdf->zoom;
	dot2->y *= fdf->zoom;
	rotation(dot1, fdf->rad);
	rotation(dot2, fdf->rad);
	iso(dot1);
	iso(dot2);
	dot1->x += fdf->shift_x;
	dot1->y += fdf->shift_y;
	dot2->x += fdf->shift_x;
	dot2->y += fdf->shift_y;
}

void	is_max(float *x_step, float *y_step, float *maxm)
{
	if (ft_abs(*x_step) >= ft_abs(*y_step))
		*maxm = *x_step;
	else
		*maxm = *y_step;
}

void	draw_pixel(t_fdf dot, t_fdf *fdf)
{
	char	*dst;

	if ((dot.x < 0 || dot.x >= 1200) || (dot.y < 0 || dot.y >= 800))
		return ;
	dst = fdf->addr + ((int)dot.y * fdf->bline + (int)dot.x * (fdf->bpp / 8));
	*(unsigned int *)dst = dot.color;
}
