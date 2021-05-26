/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:24:10 by cport             #+#    #+#             */
/*   Updated: 2019/09/22 14:49:06 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*data;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(data = ft_memalloc(content_size)))
		{
			ft_memdel((void **)new);
			return (NULL);
		}
		ft_memcpy(data, content, content_size);
		new->content = data;
		new->content_size = content_size;
	}
	else
	{
		new->content = NULL;
		new->content_size = 0;
	}
	new->next = NULL;
	return (new);
}
