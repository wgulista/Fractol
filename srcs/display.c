#include "../includes/fractol.h"
#include <stdio.h>

void		pixel_put_to_image(t_env *e, double x, double y)
{
	int 	pos;

	pos = (x * (e->img.bpp / 8)) + (y * e->img.sline);
	e->img.data[pos] = e->color_rgba.le.r;
	e->img.data[pos + 1] = e->color_rgba.le.b << 8;
	e->img.data[pos + 2] = e->color_rgba.le.g << 16;
}

int 		get_color(int i)
{
	int 	ret;

	ret = 0;
	ret += (i >> 16) & 0xFF;
	ret += (i >> 8) & 0xFF;
	ret += (i) & 0xFF;
	return (ret);
}

void		set_color(t_env *e, int color)
{
	e->color_rgba.le.r = get_color(color) + e->theme;
	e->color_rgba.le.b = get_color(color) + e->theme;
	e->color_rgba.le.g = get_color(color) + e->theme;
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
