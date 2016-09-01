#include "../includes/fractol.h"

void		move_pixel_to_left(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	e->x1 += 0.1;
	e->x2 += 0.1;
}

void		move_pixel_to_bottom(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	e->y1 -= 0.1;
	e->y2 -= 0.1;
}

void		move_pixel_to_right(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	e->x1 -= 0.1;
	e->x2 -= 0.1;
}

void		move_pixel_to_top(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	e->y1 += 0.1;
	e->y2 += 0.1;
}

void 		move(t_env *e, int keycode)
{
	if (keycode == 13)
		move_pixel_to_top(e);
	if (keycode == 0)
		move_pixel_to_left(e);
	if (keycode == 1)
		move_pixel_to_bottom(e);
	if (keycode == 2)
		move_pixel_to_right(e);
}
