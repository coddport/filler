/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:32:37 by cport             #+#    #+#             */
/*   Updated: 2019/09/12 23:14:26 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (n > 0)
	{
		i = 0;
		str1 = (unsigned char *)s1;
		str2 = (unsigned char *)s2;
		while (*str1 && *str1 == *str2 && i < n - 1)
		{
			str1++;
			str2++;
			i++;
		}
		return (*str1 - *str2);
	}
	else
		return (0);
}
