/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 13:24:56 by wgulista          #+#    #+#             */
/*   Updated: 2016/09/01 13:25:25 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			fractal_type(char **av)
{
	if (ft_strequ("M", av[1]))
		return (1);
	else if (ft_strequ("J", av[1]))
		return (2);
	else if (ft_strequ("B", av[1]))
		return (3);
	else
		return (0);
}

void		init_fractal(t_env *e, t_fractal *f)
{
	e->i_max = 100;
	f->zr = 0.0;
	f->zi = 0.0;
	f->cr = 0.0;
	f->ci = 0.0;
	e->zoom_x = WIDTH / (e->x2 - e->x1);
	e->zoom_y = HEIGHT / (e->y2 - e->y1);
}

void		init_fractal_area(t_env *e)
{
	if (e->fractal_type == 1 || e->fractal_type == 3)
	{
		e->x1 = -2.8;
		e->y1 = -1.8;
		e->x2 = 1.5;
		e->y2 = 1.8;
		e->zoom_x = WIDTH / (e->x2 - e->x1) / 10;
		e->zoom_y = HEIGHT / (e->y2 - e->y1) / 10;
	}
	else if (e->fractal_type == 2)
	{
		e->x1 = -2;
		e->y1 = -2;
		e->x2 = 2;
		e->y2 = 2;
		e->zoom_x = WIDTH / (e->x2 - e->x1);
		e->zoom_y = HEIGHT / (e->y2 - e->y1);
	}
}

void		initialize_env(t_env *e, char **av)
{
	e->fractal_type = fractal_type(av);
	e->mlx = mlx_init();
	if (e->mlx == NULL)
		ft_msg_error("MLX Init Failed !");
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Fract'ol - wgulista");
	e->img.img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->img.data = mlx_get_data_addr(e->img.img, &e->img.bpp, \
		&e->img.sline, &e->img.endian);
	e->theme = 1;
	e->help = 0;
	e->cam.x = 0;
	e->cam.y = 0;
	e->x1 = 0.0;
	e->y1 = 0.0;
	e->x2 = 0.0;
	e->y2 = 0.0;
	e->i_max = 100;
	e->pause = 0;
	init_fractal_area(e);
}
