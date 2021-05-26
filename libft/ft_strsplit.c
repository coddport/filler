/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:08:40 by cport             #+#    #+#             */
/*   Updated: 2019/09/22 19:11:36 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t	ft_tokcnt(char const *s, char c)
{
	size_t		len;
	int			flag;

	len = 0;
	flag = 0;
	while (*s)
	{
		if (*s == c && flag == 1)
			flag = 0;
		if (*s != c && flag == 0)
		{
			len++;
			flag = 1;
		}
		s++;
	}
	return (len);
}

static size_t	ft_toklen(char const *s, char c)
{
	size_t		len;

	len = 0;
	while (*s != '\0' && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

static char		**ft_arrdel(char **arr, size_t j)
{
	while (j + 1 > 0)
		ft_strdel(&arr[j--]);
	arr = NULL;
	return (arr);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**arr;
	size_t		len;
	size_t		j;

	if (!s || !(arr = (char **)malloc((ft_tokcnt(s, c) + 1) * sizeof(char *))))
		return (NULL);
	j = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0' && *s != c)
		{
			len = ft_toklen(s, c);
			if (!(arr[j] = ft_strnew(len)))
				return (ft_arrdel(arr, j));
			ft_strncpy(arr[j], s, len);
			s += len;
			j++;
		}
	}
	arr[j] = NULL;
	return (arr);
}
