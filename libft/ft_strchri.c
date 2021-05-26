/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mironbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:10:10 by cport             #+#    #+#             */
/*   Updated: 2020/08/12 23:14:26 by mironbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strchri(const char *s, int c)
{
	size_t	i;
	char	chr;

	chr = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == chr)
			return ((int)i);
		i++;
	}
	return (-1);
}
