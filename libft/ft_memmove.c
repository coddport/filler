/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 07:56:32 by cport             #+#    #+#             */
/*   Updated: 2019/09/22 13:20:12 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	if (!s1 && !s2)
		return (NULL);
	if (tmp2 > tmp1)
	{
		while (n--)
			*tmp1++ = *tmp2++;
	}
	else
	{
		while (n--)
			tmp1[n] = tmp2[n];
	}
	return (s1);
}
