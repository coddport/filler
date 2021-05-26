/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:55:58 by cport             #+#    #+#             */
/*   Updated: 2019/09/22 06:09:19 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		len;
	int		i;

	len = ft_intlen(n);
	if (!(str = ft_strnew(len)))
		return (NULL);
	num = (long)n;
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	i = len - 1;
	while (num > 9)
	{
		str[i--] = num % 10 + '0';
		num /= 10;
	}
	str[i] = num + '0';
	return (str);
}
