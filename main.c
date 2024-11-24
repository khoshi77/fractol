#include "./fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	if (!s1 || !s2)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[i] || str2[i]) && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

double	ft_atof2(char *nptr, int i, double ans)
{
	double	num;

	if (nptr[i] == '.')
	{
		i++;
		num = 0.1;
		while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
		{
			ans += (nptr[i++] - '0') * num;
			num *= 0.1;
		}
	}
	return (ans);
}

double	ft_atof(char *nptr)
{
	int		i;
	int		sign;
	double	ans;

	i = 0;
	sign = 1;
	ans = 0.0;
	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' '))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i++] == '-')
			sign = -1;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
		ans = ans * 10 + (nptr[i++] - '0');
	ans = sign * ft_atof2(nptr, i, ans);
	return (ans);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (!((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) || \
	(argc == 4 && !ft_strncmp(argv[1], "julia", 5))))
	{
		write(1, "Please select one option\n\n", 26);
		write(1, "mandelbrot\n", 11);
		write(1, "julia a b\n", 10);
		return (1);
	}
	vars.mlx = mlx_init();
	vars.type = argv[1];
	if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		vars.c_a = ft_atof(argv[2]);
		vars.c_b = ft_atof(argv[3]);
	}
	vars.img.zoom = 1.0;
	vars.window = mlx_new_window(vars.mlx, WIDTH, HEIGHT, argv[1]);
	mlx_key_hook(vars.window, key_hook, &vars);
	mlx_mouse_hook(vars.window, mouse_hook, &vars);
	mlx_hook(vars.window, 17, 0, close_window, &vars);
	put_fractol(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
