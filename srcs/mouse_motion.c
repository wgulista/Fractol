#include "../includes/fractol.h"

int			mouse_motion(int x, int y, t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	e->mouse_x = scale_x(e, x);
	e->mouse_y = scale_y(e, y);
	expose_hook(e);
	return (0);
}