/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitdel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:08:40 by cport             #+#    #+#             */
/*   Updated: 2020/11/16 15:16:25 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_strsplitdel(char ***tokens)
{
	char	**x;

	if (tokens && *tokens)
	{
		x = ((*tokens));
		while ((*x))
			free((*(x++)));
		free((*tokens));
		(*tokens) = NULL;
	}
	return ;
}
