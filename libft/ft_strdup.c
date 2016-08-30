/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <wgulista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:34:02 by wgulista          #+#    #+#             */
/*   Updated: 2016/01/01 16:28:50 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		size;
	char	*cpy;

	i = 0;
	size = ft_strlen(src);
	cpy = (char*)malloc(sizeof(char) * (size + 1));
	if (cpy != NULL)
	{
		while (i < size)
		{
			cpy[i] = src[i];
			i++;
		}
		cpy[i] = '\0';
		return (cpy);
	}
	else
		return (NULL);
}
