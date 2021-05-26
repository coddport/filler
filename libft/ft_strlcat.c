/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:11:41 by cport             #+#    #+#             */
/*   Updated: 2019/09/22 10:51:13 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		len_d;

	i = 0;
	j = 0;
	len_d = ft_strlen(dst);
	if (size <= len_d)
		return (ft_strlen(src) + size);
	while (dst[i] != '\0' && i + 1 < size)
		i++;
	while (src[j] != '\0' && i + 1 < size)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (len_d + ft_strlen(src));
}
