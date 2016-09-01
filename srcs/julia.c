#include "../includes/fractol.h"

void		julia(t_env *e, t_fractal *f)
{
	f->cr = e->mouse_x;
	f->ci = e->mouse_y;
	f->zr = e->cam.x / e->zoom_x + e->x1;
	f->zi = e->cam.y / e->zoom_y + e->y1;
	f->i = 0;
	f->i = 0;
	while (f->zr * f->zr + f->zi * f->zi < 4 && f->i < e->i_max)
	{
		f->tmp = f->zr;
		f->zr = f->zr * f->zr - f->zi * f->zi + f->cr;
		f->zi = 2.0 * f->tmp * f->zi + f->ci;
		++f->i;
	}
	if (f->i == e->i_max)
		set_color(e, 0);
	else
		set_color(e, (f->i % 256) * 255 / e->i_max);
}
