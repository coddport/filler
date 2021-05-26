/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:56:53 by cport             #+#    #+#             */
/*   Updated: 2019/09/22 18:17:08 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*current;
	t_list	*following;

	if (!lst || !f)
		return (NULL);
	current = f(lst);
	following = current;
	while (lst->next != NULL)
	{
		lst = lst->next;
		if (!(current->next = f(lst)))
		{
			free(current->next);
			return (NULL);
		}
		current = current->next;
	}
	return (following);
}
