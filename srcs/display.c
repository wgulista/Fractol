#include "../includes/fractol.h"

void		pixel_put_to_image(t_env *e, double x, double y)
{
	int 	pos;

	pos = (x * (e->img.bpp / 8)) + (y * e->img.sline);
	e->img.data[pos] = e->color_rgba.le.r;
	e->img.data[pos + 1] = e->color_rgba.le.b;
	e->img.data[pos + 2] = e->color_rgba.le.g;
}

int 		get_color(int i)
{
	int 	ret;

	ret = 0;
	ret += (unsigned char)(255 + (255 * sin((double)i/40))) << 16;
	ret += (unsigned char)(255 - (125 * cos((double)i/80))) << 8;
	ret += (unsigned char)(255 + (125 * cos((double)i/120)));
	return (ret);
}

void		set_color(t_env *e, int color)
{
	color += e->theme;
	e->color_rgba.le.r = color;
	e->color_rgba.le.b = color;
	e->color_rgba.le.g = color;
	//e->color_rgba.whole = color;
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
