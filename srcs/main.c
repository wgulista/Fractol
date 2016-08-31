#include "../includes/fractol.h"

void		check_arg(int ac, char **av)
{
	if (ac < 2 || ac > 2)
		ft_usage_error();
	if (!(ft_strequ("M", av[1]) || ft_strequ("J", av[1]) || \
		ft_strequ("B", av[1])))
		ft_usage_error();
}

int 		main(int ac, char **av)
{
	t_env	e;

	check_arg(ac, av);
	initialize_env(&e, av);
	mlx_hook(e.win, KEYPRESS, KEYPRESS_MASK, key_hook, &e);
	mlx_hook(e.win, BUTTONPRESS, BUTTONPRESS_MASK, mouse_hook, &e);
	if (e.fractal_type == 2)
		mlx_hook(e.win, MOTION_NOTIFY, PTR_MOTION_MASK, mouse_motion, &e);
	mlx_hook(e.win, EXPOSE, EXPOSE_MASK, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
