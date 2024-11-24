#include "./fractol.h"

void	select_rgb1(double hue, double *r, double *g, double *b)
{
	double	x_val;

	x_val = 0.5 - fabs(fmod(hue / 60.0, 2) - 1);
	if (hue >= 0 && hue < 60)
	{
		*r = 1;
		*g = x_val;
		*b = 0;
	}
	else if (hue >= 60 && hue < 120)
	{
		*r = x_val;
		*g = 1;
		*b = 0;
	}
	else
	{
		*r = 0;
		*g = 1;
		*b = x_val;
	}
}

void	select_rgb2(double hue, double *r, double *g, double *b)
{
	double	x_val;

	x_val = 0.5 - fabs(fmod(hue / 60.0, 2) - 1);
	if (hue >= 180 && hue < 240)
	{
		*r = 0;
		*g = x_val;
		*b = 1;
	}
	else if (hue >= 240 && hue < 300)
	{
		*r = x_val;
		*g = 0;
		*b = 1;
	}
	else
	{
		*r = 1;
		*g = 0;
		*b = x_val;
	}
}

void	drew_color(t_vars *vars, double x, double y, int *i)
{
	int		color;
	double	hue;
	t_color	rgb;

	hue = (double)(*i) / MAX_ITER * 360;
	color = 0;
	if (hue >= 0 && hue < 180)
		select_rgb1(hue, &rgb.r, &rgb.g, &rgb.b);
	else
		select_rgb2(hue, &rgb.r, &rgb.g, &rgb.b);
	rgb.red = (int)(rgb.r * 255);
	rgb.green = (int)(rgb.g * 255);
	rgb.blue = (int)(rgb.b * 255);
	color = (rgb.red << 16) | (rgb.green << 8) | rgb.blue;
	my_mlx_pixel_put(&vars->img, x, y, color);
}
