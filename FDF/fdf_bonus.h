#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "libft/libft.h"

# if __unix__
#  include "minilibx/mlx.h"
#  define KEY_ESC 65307
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_PLUS 61
#  define KEY_MINUS 45
#  define ROTATE1 114
#  define ROTATE2 116
#  define KEY_THREE 51
#  define KEY_TWO 50
#  define KEY_Q 113

# else
#  include "minilibx_macos/mlx.h"
#  define KEY_ESC 53
#  define KEY_Q 12
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_PLUS 24
#  define KEY_MINUS 27
#  define ROTATE1 15
#  define ROTATE2 17
#  define KEY_THREE 20
#  define KEY_TWO 19

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
	int		iso;
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