/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:41:10 by cport             #+#    #+#             */
/*   Updated: 2019/10/21 18:51:46 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (!ptr)
		return (ft_memalloc(size));
	else if (size == 0)
	{
		ft_memdel(&ptr);
		return (ptr);
	}
	else if (sizeof(ptr) >= size)
		return (ptr);
	else if (!(new_ptr = ft_memalloc(size)))
		return (NULL);
	ft_memcpy(new_ptr, ptr, size);
	ft_memdel(&ptr);
	return (new_ptr);
}
