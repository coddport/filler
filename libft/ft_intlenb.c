/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlenb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mironbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:04:42 by cport             #+#    #+#             */
/*   Updated: 2020/08/12 23:08:21 by mironbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_intlenb(uintmax_t nb, int base)
{
	int i;

	i = 0;
	if (base < 1)
		return (i);
	if (nb == 0)
		return (1);
	if (base == 1)
		return ((int)nb);
	while (nb && ++i)
		nb /= base;
	return (i);
}
