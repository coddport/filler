/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:13:27 by cport             #+#    #+#             */
/*   Updated: 2019/09/22 06:11:49 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	len = ft_strlen(s);
	while (len > 0
			&& (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n'))
		len--;
	return (ft_strsub(s, 0, len));
}
