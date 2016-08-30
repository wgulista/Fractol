/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:09:33 by wgulista          #+#    #+#             */
/*   Updated: 2015/12/31 13:37:52 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new_str;

	i = 0;
	new_str = ft_strnew(len);
	if (new_str != NULL)
	{
		while (i < len)
		{
			new_str[i] = s[start + i];
			i++;
		}
	}
	return (new_str);
}