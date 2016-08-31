#include "../includes/fractol.h"

void			quit_program(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img.img);
	mlx_destroy_window(e->mlx, e->win);
	exit(1);
}

void			display_menu(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 10, 0xFFFF00, "h : help");
	if (e->help == 1)
	{
		mlx_string_put(e->mlx, e->win, 10, 30, 0xF8F8FF, "Echap    : Permet de quitter le programme");
		mlx_string_put(e->mlx, e->win, 10, 45, 0xF8F8FF, "Fleche   : Permet de deplacer");
		mlx_string_put(e->mlx, e->win, 10, 60, 0xF8F8FF, "1 2 3    : Change de fractal");
		mlx_string_put(e->mlx, e->win, 10, 75, 0xF8F8FF, "T        : Change la couleur");
		mlx_string_put(e->mlx, e->win, 10, 90, 0xF8F8FF, "Souris   : Cliquer pour zoomer");
	}
}

void			select_fractal(t_env *e, t_fractal *f)
{
	e->cam.x = -1.0;
	while (++e->cam.x < WIDTH)
	{
		e->cam.y = -1.0;
		while(++e->cam.y < HEIGHT)
		{
			if (e->fractal_type == 1)
				mandelbrot(e, f);
			else if (e->fractal_type == 2)
				julia(e, f);
			else if (e->fractal_type == 3)
				burnship(e, f);
			else
				ft_usage_error();
		}
	}
}

int				expose_hook(t_env *e)
{
	t_fractal	*f;

	if (!(f = (t_fractal *)malloc(sizeof(t_fractal))))
		ft_msg_error("Memory Allocation failed for fractal !");
	init_fractal(e, f);
	select_fractal(e, f);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	display_menu(e);
	free(f);
	return (0);
}

int				key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		quit_program(e);
	else if (keycode == H)
		e->help = (e->help) ? 0 : 1;
	else if (keycode == KEY_1)
		e->fractal_type = 1;
	else if (keycode == KEY_2 || keycode == KEY_3)
		e->fractal_type = keycode == KEY_2 ? 2 : 3;
	else if (keycode == 49)
	{
		init_fractal_area(e);
		e->theme = 0;
		e->color_rgba.whole = 0;
		e->mouse_x = 0;
		e->mouse_y = 0;
		e->i_max = 50;
	}
	else if (keycode == KEY_T)
		e->theme += 2;
	else if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		move(e, keycode);
	expose_hook(e);
	return (0);
}
