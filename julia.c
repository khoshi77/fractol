#include "./fractol.h"

int	calc_julia(double x, double y, double cx, double cy)
{
	int			i;
	t_complex	z;
	t_complex	ex_z;

	z.a = x;
	z.b = y;
	i = 0;
	while (i < MAX_ITER)
	{
		ex_z.a = z.a;
		ex_z.b = z.b;
		z.a = ex_z.a * ex_z.a - ex_z.b * ex_z.b + cx;
		z.b = 2 * ex_z.a * ex_z.b + cy;
		if (z.a * z.a + z.b * z.b > 4)
			return (i);
		i++;
	}
	return (-1);
}

void	put_julia(t_vars *vars)
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
			i = calc_julia(a, b, vars->c_a, vars->c_b);
			if (i == -1)
				my_mlx_pixel_put(&vars->img, x, y, 0x00000000);
			else
				drew_color(vars, x, y, &i);
			x++;
		}
		y++;
	}
}
