/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 13:25:16 by wgulista          #+#    #+#             */
/*   Updated: 2016/09/01 13:25:20 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		move_pixel_to_left(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	e->x1 += 0.05;
	e->x2 += 0.05;
}

void		move_pixel_to_bottom(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	e->y1 -= 0.05;
	e->y2 -= 0.05;
}

void		move_pixel_to_right(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	e->x1 -= 0.05;
	e->x2 -= 0.05;
}

void		move_pixel_to_top(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	e->y1 += 0.05;
	e->y2 += 0.05;
}

void		move(t_env *e, int keycode)
{
	if (keycode == 13 || keycode == 126)
		move_pixel_to_top(e);
	if (keycode == 0 || keycode == 123)
		move_pixel_to_left(e);
	if (keycode == 1 || keycode == 125)
		move_pixel_to_bottom(e);
	if (keycode == 2 || keycode == 124)
		move_pixel_to_right(e);
}
