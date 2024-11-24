#include "./fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	put_fractol(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx, 500, 500);
	vars->img.addr = mlx_get_data_addr(vars->img.img, \
	&vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	if (!ft_strncmp(vars->type, "mandelbrot", 10))
		put_mandelbrot(vars);
	else if (!ft_strncmp(vars->type, "julia", 5))
		put_julia(vars);
	mlx_put_image_to_window(vars->mlx, vars->window, vars->img.img, 0, 0);
	mlx_destroy_image(vars->mlx, vars->img.img);
	return (0);
}
