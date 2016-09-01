/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 13:25:12 by wgulista          #+#    #+#             */
/*   Updated: 2016/09/01 13:25:38 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		plus_zoom(t_env *e, double *x1, double *y1)
{
	e->zoom_x += 0.05;
	e->zoom_y += 0.05;
	e->x1 = *x1 - (e->x2 - e->x1) / 4;
	e->x2 = *x1 + (e->x2 - e->x1) / 4;
	e->y1 = *y1 - (e->y2 - e->y1) / 4;
	e->y2 = *y1 + (e->y2 - e->y1) / 4;
	e->i_max += 10;
}

void		minus_zoom(t_env *e, double *x1, double *y1)
{
	e->zoom_x -= 0.05;
	e->zoom_y -= 0.05;
	e->x1 = *x1 - (e->x2 - e->x1);
	e->x2 = *x1 + (e->x2 - e->x1);
	e->y1 = *y1 - (e->y2 - e->y1);
	e->y2 = *y1 + (e->y2 - e->y1);
	e->i_max -= 10;
}

int			mouse_hook(int keycode, int x, int y, t_env *e)
{
	double	x1;
	double	y1;

	x1 = scale_x(e, x);
	y1 = scale_y(e, y);
	mlx_clear_window(e->mlx, e->win);
	if (keycode == MOUSE_CLIC_L || keycode == MOUSE_WHEEL_DOWN)
		plus_zoom(e, &x1, &y1);
	else if (keycode == MOUSE_CLIC_R || keycode == MOUSE_WHEEL_UP)
		if (e->zoom_x > 66 && e->zoom_y > 47)
			minus_zoom(e, &x1, &y1);
	expose_hook(e);
	return (0);
}
