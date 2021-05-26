/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:13:01 by cport             #+#    #+#             */
/*   Updated: 2019/09/19 20:49:25 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	chr;
	char	*res;

	chr = (char)c;
	res = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == chr)
			res = (char *)&s[i];
		i++;
	}
	if (chr == 0 && s[i] == chr)
		res = (char *)&s[i];
	return ((char *)res);
}
