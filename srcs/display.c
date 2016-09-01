/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 13:24:51 by wgulista          #+#    #+#             */
/*   Updated: 2016/09/01 13:25:24 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		pixel_put_to_image(t_env *e, double x, double y)
{
	int		pos;

	pos = (x * (e->img.bpp / 8)) + (y * e->img.sline);
	if (e->theme == 0)
	{
		e->img.data[pos] = e->color_rgb.whole;
		e->img.data[pos + 1] = e->color_rgb.whole >> 8;
		e->img.data[pos + 2] = e->color_rgb.whole >> 16;
	}
	else if (e->theme == 1)
	{
		e->img.data[pos] = e->color_rgb.whole >> 16;
		e->img.data[pos + 1] = e->color_rgb.whole >> 8;
		e->img.data[pos + 2] = e->color_rgb.whole;
	}
	else
	{
		e->img.data[pos] = e->color_rgb.whole >> 8;
		e->img.data[pos + 1] = e->color_rgb.whole;
		e->img.data[pos + 2] = e->color_rgb.whole >> 16;
	}
}

void		set_color(t_env *e, int color)
{
	e->theme = (e->theme > 2 ? e->theme - 3 : e->theme);
	e->color_rgb.whole = color + e->theme * 0.5;
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
