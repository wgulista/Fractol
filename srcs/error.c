#include "../includes/fractol.h"

void		ft_usage_error()
{
	ft_putendl("Usage: ./fractol M/J/S");
	ft_putendl("M: Mandelbrot");
	ft_putendl("J: Julia");
	ft_putendl("B: Burning Ship");
	exit(1);
}

void		ft_msg_error(char *msg)
{
	if (msg != NULL)
		ft_putendl(msg);
	else
		ft_putendl("Error");
	exit(1);
}
