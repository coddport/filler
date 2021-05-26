/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:13:14 by cport             #+#    #+#             */
/*   Updated: 2019/09/19 20:13:16 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i] != '\0' && i < size)
	{
		j = 0;
		while (s1[i + j] == s2[j] && i + j < size)
		{
			if (s2[j + 1] == '\0' || i + j == size)
				return ((char *)&s1[i]);
			j++;
		}
		i++;
	}
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	else
		return (NULL);
}
