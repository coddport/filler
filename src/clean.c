/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 06:07:54 by cport             #+#    #+#             */
/*   Updated: 2020/11/16 15:15:13 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	*clean_map(t_state *f, int j)
{
	while (--j >= 0)
		free(f->map->proximity[j]);
	free(f->map->proximity);
	free(f->map);
	reset_state(f);
	return (NULL);
}

void	*clean_token(t_state *f, int j)
{
	while (--j >= 0)
		free(f->token->form[j]);
	free(f->token->form);
	free(f->token);
	return (clean_map(f, f->map->h));
}

void	reset_state(t_state *f)
{
	f->token = NULL;
	f->map = NULL;
	f->y = -1;
	f->x = -1;
}
