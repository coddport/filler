/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:33:29 by cport             #+#    #+#             */
/*   Updated: 2019/09/22 16:45:43 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_lstlen(t_list *lst)
{
	size_t	i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	while (lst != NULL)
	{
		if (ft_oversiz(i, 1) == 1)
			return (0);
		else
		{
			tmp = tmp->next;
			i++;
		}
	}
	return (i);
}
