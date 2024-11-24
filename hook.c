#include "./fractol.h"

int	key_hook(int key_code, t_vars *vars)
{
	if (key_code == 65307)
	{
		write(1, "closed window\n", 15);
		mlx_destroy_window(vars->mlx, vars->window);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(0);
	}
	return (0);
}

int	close_window(t_vars *vars)
{
	write(1, "closed window\n", 15);
	mlx_destroy_window(vars->mlx, vars->window);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	if (button == 4)
	{
		if (vars->img.zoom > 0)
			vars->img.zoom -= 0.05;
	}
	else if (button == 5)
	{
		vars->img.zoom += 0.05;
	}
	put_fractol(vars);
	(void) x;
	(void) y;
	return (0);
}
