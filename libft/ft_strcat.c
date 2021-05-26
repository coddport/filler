/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:10:17 by cport             #+#    #+#             */
/*   Updated: 2019/09/20 22:58:15 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	size_t			len;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	len = ft_strlen(s1);
	while (*tmp2)
		tmp1[len++] = *tmp2++;
	tmp1[len] = '\0';
	return (s1);
}
