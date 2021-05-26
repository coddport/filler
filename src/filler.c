/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 06:07:54 by cport             #+#    #+#             */
/*   Updated: 2020/10/24 22:25:42 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>

int		weight_gcs(t_state *f, int j, int i, int prox)
{
	int		overlap;
	int		y;
	int		x;

	overlap = 0;
	y = -1;
	while (++y < f->token->h && (x = -1))
		while (++x < f->token->w)
			if (f->token->form[y][x] == '*')
			{
				if (j + y >= f->map->h || i + x >= f->map->w || j + y < 0
						|| i + x < 0 || f->map->proximity[j + y][i + x] == -2)
					return (-1);
				if (f->map->proximity[j + y][i + x] == -1)
					overlap++;
				prox += f->map->proximity[j + y][i + x];
			}
	if (overlap == 1)
		return (prox);
	return (-1);
}

void	get_gcs(t_state *f, int j, int i)
{
	int		min;
	int		prox;

	min = 2147483647;
	while (++j < f->map->h + f->token->h && (i = -(f->token->h + 1)))
		while (++i < f->map->w + f->token->w)
		{
			prox = weight_gcs(f, j, i, 0);
			if (prox < min && prox != -1)
			{
				min = prox;
				f->y = j;
				f->x = i;
			}
		}
	ft_printf("%d %d\n", f->y, f->x);
	clean_token(f, f->token->h);
}

int		main(void)
{
	t_state	filler;
	int		fd;

	fd = 0;
	if (get_player(&filler, fd))
		return (1);
	while (!get_map(&filler, fd) && !get_token(&filler, fd))
		get_gcs(&filler, -(filler.token->h), -(filler.token->w));
	return (0);
}
