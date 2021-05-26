/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 06:55:37 by cport             #+#    #+#             */
/*   Updated: 2019/09/22 03:28:57 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	if (!s1 && !s2)
		return (s1);
	if (n > 0)
	{
		tmp1 = (unsigned char *)s1;
		tmp2 = (unsigned char *)s2;
		while (n--)
			*tmp1++ = *tmp2++;
	}
	return (s1);
}
