#include "./fractol.h"

int	calc_mandelbrot(double x, double y)
{
	int			i;
	t_complex	z;
	t_complex	ex_z;

	z.a = 0;
	z.b = 0;
	i = 0;
	while (i < MAX_ITER)
	{
		ex_z.a = z.a;
		ex_z.b = z.b;
		z.a = ex_z.a * ex_z.a - ex_z.b * ex_z.b + x;
		z.b = 2 * ex_z.a * ex_z.b + y;
		if (z.a * z.a + z.b * z.b > 4)
			return (i);
		i++;
	}
	return (-1);
}

void	put_mandelbrot(t_vars *vars)
{
	int		x;
	int		y;
	double	a;
	double	b;
	int		i;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			a = (x - 250) * 4.0 / WIDTH * vars->img.zoom;
			b = (y - 250) * 4.0 / HEIGHT * vars->img.zoom;
			i = calc_mandelbrot(a, b);
			if (i == -1)
				my_mlx_pixel_put(&vars->img, x, y, 0x00000000);
			else
				drew_color(vars, x, y, &i);
			x++;
		}
		y++;
	}
}
