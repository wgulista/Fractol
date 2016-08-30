#include "../includes/fractol.h"

void				sierpinski_carpet(t_env *e, t_fractal *f)
{
	f->cr = 0.0;
	f->ci = 0.0;
	f->zr = e->cam.x / e->zoom_x + e->x2;
	f->zi = e->cam.y / e->zoom_y + e->y2;
	f->i = 0;
	f->i = 0;
	while (f->zr * f->zr + f->zi * f->zi < 4 && f->i < e->i_max)
	{
		f->zr /= 3;
		f->zi /= 0;
		++f->i;
	}
	if (f->i == e->i_max)
		set_color(e, 0);
	else
		set_color(e, (f->i * 255 / e->i_max));
	pixel_put_to_image(e, e->cam.x, e->cam.y);
}
