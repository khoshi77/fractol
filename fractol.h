#ifndef FRACTOL_H
# define FRACTOL_H

# include "./minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define WIDTH 500
# define HEIGHT 500
# define MAX_ITER 100

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	zoom;
}			t_img;

typedef struct s_vars
{
	void	*mlx;
	void	*window;
	char	*type;
	t_img	img;
	double	c_a;
	double	c_b;
}			t_vars;

typedef struct s_complex
{
	double	a;
	double	b;
}			t_complex;

typedef struct s_color
{
	int		red;
	int		green;
	int		blue;
	double	r;
	double	g;
	double	b;
}			t_color;

int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	drew_color(t_vars *vars, double x, double y, int *i);

int		key_hook(int key_code, t_vars *vars);
int		close_window(t_vars *vars);
int		mouse_hook(int button, int x, int y, t_vars *vars);

void	put_julia(t_vars *vars);
void	put_mandelbrot(t_vars *vars);

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		put_fractol(t_vars *vars);

#endif
