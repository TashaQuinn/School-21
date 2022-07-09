#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"

# if __unix__
#  include "minilibx/mlx.h"
#  define KEY_ESC 65307

# else
#  include "minilibx_macos/mlx.h"
#  define KEY_ESC 53

# endif

typedef struct s_fdf
{
	float	x;
	float	y;
	float	z;
	int		color;
	int		hex_color;
	int		last;
	float	zoom;
	int		shift_x;
	int		shift_y;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bpp;
	int		bline;
	int		endian;
	float	rad;
}			t_fdf;

t_fdf	**parse_map(char *file_name);
void	input_check(int argc, char **argv);
int		keys(int key, t_fdf **fdf);
char	*ft_strchr(const char *str, int c);
void	draw_pixel(t_fdf dot, t_fdf *fdf);
void	is_max(float *x_step, float *y_step, float *maxm);
void	set_params(t_fdf *dot1, t_fdf *dot2, t_fdf *fdf);
void	draw(t_fdf **fdf);

#endif