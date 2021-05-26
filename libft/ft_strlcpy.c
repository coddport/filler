/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:11:34 by cport             #+#    #+#             */
/*   Updated: 2019/09/22 02:18:49 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const char	*osrc;
	size_t		i;

	osrc = src;
	if (size > 0)
	{
		i = 0;
		while (*src != '\0' && i < size - 1)
		{
			*dst++ = *src++;
			i++;
		}
		if (i == size - 1 || *src == '\0')
			*dst = '\0';
	}
	return (ft_strlen(osrc));
}
