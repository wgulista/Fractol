#include "../includes/fractol.h"

void		pixel_put_to_image(t_env *e, double x, double y)
{
	int 	pos;

	pos = (x * (e->img.bpp / 8)) + (y * e->img.sline);
	e->img.data[pos] = e->color_rgba.whole;
	e->img.data[++pos] = e->color_rgba.whole;
	e->img.data[++pos] = e->color_rgba.whole;
}

int 		get_color(int i)
{
	int 	ret;

	ret = 0;
	ret += i % 256 + i * 125;
	return (ret);
}

void		set_color(t_env *e, int color)
{
	e->color_rgba.whole = color + e->theme;
}

double		scale_x(t_env *e, double x)
{
	double dx;

	dx = (((e->x2 - e->x1) * x) / WIDTH) + e->x1;
	return (dx);
}

double		scale_y(t_env *e, double y)
{
	double	dy;

	dy = (((e->y2 - e->y1) * y) / HEIGHT) + e->y1;
	return (dy);
}
