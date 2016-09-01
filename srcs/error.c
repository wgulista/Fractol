/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 13:24:59 by wgulista          #+#    #+#             */
/*   Updated: 2016/09/01 13:25:27 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_usage_error(void)
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
