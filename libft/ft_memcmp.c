/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 23:20:12 by cport             #+#    #+#             */
/*   Updated: 2019/09/12 23:40:02 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	size_t			i;

	if (n > 0)
	{
		tmp1 = (unsigned char *)s1;
		tmp2 = (unsigned char *)s2;
		i = 0;
		while (*tmp1 == *tmp2 && i < n - 1)
		{
			tmp1++;
			tmp2++;
			i++;
		}
		return (*tmp1 - *tmp2);
	}
	else
		return (0);
}
