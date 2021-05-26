/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:09:27 by cport             #+#    #+#             */
/*   Updated: 2019/09/22 13:02:20 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	x;

	if (n > 0)
	{
		tmp = (unsigned char *)s;
		x = (unsigned char)c;
		while (n-- > 0)
		{
			if (*tmp == x)
				return (tmp);
			tmp++;
		}
	}
	return (NULL);
}
