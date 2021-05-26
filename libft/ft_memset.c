/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 01:24:16 by cport             #+#    #+#             */
/*   Updated: 2019/09/13 05:42:41 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	if (n > 0)
	{
		i = 0;
		str = (unsigned char *)s;
		while (i < n)
		{
			str[i] = (unsigned char)c;
			i++;
		}
	}
	return (s);
}
