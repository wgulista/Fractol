#include "../includes/fractol.h"
#include <stdio.h>

int			mouse_hook(int keycode, int x, int y, t_env *e)
{
	double	x1;
	double	y1;

	x1 = scale_x(e, x);
	y1 = scale_y(e, y);
	if (keycode == MOUSE_CLIC_L || keycode == MOUSE_WHEEL_DOWN)
	{
		e->zoom_x += 1.0;
		e->zoom_y += 1.0;
		e->i_max += 10;
	}
	else if (keycode == MOUSE_CLIC_R || keycode == MOUSE_WHEEL_UP)
	{
		e->zoom_x -= 1.0;
		e->zoom_y -= 1.0;
		e->i_max -= 10;
	}
	expose_hook(e);
	return (0);
}
