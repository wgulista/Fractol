/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:32:28 by wgulista          #+#    #+#             */
/*   Updated: 2015/12/31 13:42:15 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*ft_memalloc(size_t size)
{
	size_t	i;
	char	*buffer;

	buffer = (char *)malloc(size);
	if (buffer != NULL)
	{
		i = 0;
		while (i < size)
		{
			buffer[i] = 0;
			i++;
		}
	}
	return ((void *)buffer);
}
