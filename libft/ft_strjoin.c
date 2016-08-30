/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <wgulista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:18:40 by wgulista          #+#    #+#             */
/*   Updated: 2015/12/03 14:56:11 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t		size1;
	size_t		size2;
	char		*new_str;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	new_str = ft_strnew(size1 + size2);
	if (new_str != NULL)
	{
		ft_strcpy(new_str, s1);
		ft_strcpy(&(new_str[size1]), s2);
	}
	return (new_str);
}
