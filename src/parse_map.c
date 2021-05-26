/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 06:07:54 by cport             #+#    #+#             */
/*   Updated: 2020/11/16 15:14:22 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		fill_proximity(char *line, int j, t_state *f)
{
	int		i;
	int		err;

	err = 0;
	i = -1;
	while (!err && ++i < f->map->w)
		if (line[i] == '.')
			f->map->proximity[j][i] = 0;
		else if (line[i] == f->me || line[i] == f->me + 32)
			f->map->proximity[j][i] = -1;
		else if (line[i] == f->en || line[i] == f->en + 32)
			f->map->proximity[j][i] = -2;
		else
			err = 1;
	err ? perror("Error: wrong char") : 0;
	return (err);
}

void	calculate_proximity(t_state *f, int j, int i)
{
	int		min;
	int		prox;

	while (++f->y < f->map->h && (f->x = -1))
		while (++f->x < f->map->w && (min = 2147483647))
			if (f->map->proximity[f->y][f->x] == 0 && (j = -1))
			{
				while (++j < f->map->h && (i = -1))
					while (++i < f->map->w)
						if (f->map->proximity[j][i] == -2)
						{
							prox = ft_mod(j - f->y) + ft_mod(i - f->x);
							(prox < min) ? min = prox : 0;
						}
				f->map->proximity[f->y][f->x] = min;
			}
	f->y = -1;
	f->x = -1;
}

int		**get_proximity(t_state *f, int fd, size_t len)
{
	int		j;
	char	*line;
	int		err;

	err = 0;
	j = -1;
	if (get_next_line(fd, &line) == 1)
	{
		(ft_strlen(line) != len) ? err = 1 : 0;
		ft_strdel(&line);
	}
	while (!err && ++j < f->map->h)
		if (get_next_line(fd, &line) == 1)
		{
			(ft_strlen(line) != len) ? err = 1 : 0;
			(!err) ? err = fill_proximity(&line[4], j, f) : 0;
			ft_strdel(&line);
		}
		else
			err = 1;
	err ? perror("Error: proximity") : calculate_proximity(f, 0, 0);
	return (err ? clean_map(f, f->map->h) : f->map->proximity);
}

int		**init_proximity(t_state *f, t_map *m, int fd)
{
	int		j;

	j = -1;
	if (!(m->proximity = (int **)malloc(sizeof(int *) * m->h)))
		return (clean_map(f, 0));
	else
		while (++j < m->h)
			if (!(m->proximity[j] = (int *)malloc(sizeof(int) * m->w)))
				return (clean_map(f, j));
	return (get_proximity(f, fd, (size_t)(m->w + 4)));
}

int		get_map(t_state *f, int fd)
{
	char	*line;
	int		err;

	err = 1;
	if (get_next_line(fd, &line) == 1)
	{
		if (!ft_strncmp(line, "Plateau ", 8))
		{
			f->y = ft_atoi(&line[8]);
			f->x = ft_atoi(ft_strchr(&line[8], ' '));
		}
		ft_strdel(&line);
	}
	if (f->y > 0 && f->x > 0 && (f->map = (t_map *)malloc(sizeof(t_map))))
	{
		f->map->h = f->y;
		f->map->w = f->x;
		f->y = -1;
		f->x = -1;
		if ((f->map->proximity = init_proximity(f, f->map, fd)))
			err = 0;
	}
	err ? perror("No map supplied: end of game") : 0;
	return (err);
}
