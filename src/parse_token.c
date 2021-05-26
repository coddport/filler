/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 06:07:54 by cport             #+#    #+#             */
/*   Updated: 2020/11/19 11:20:04 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	**init_form(t_state *f, t_token *t, int fd, size_t len)
{
	int		j;
	int		i;

	j = -1;
	if (!(t->form = (char **)malloc(sizeof(char *) * t->h)))
		return (clean_token(f, 0));
	else
		while (++j < t->h)
			if (get_next_line(fd, &(t->form[j])) < 1
					|| ft_strlen(t->form[j]) != len)
				return (clean_token(f, j));
			else
			{
				i = -1;
				while (++i < t->w)
					if (t->form[j][i] != '.' && t->form[j][i] != '*')
						return (clean_token(f, j));
			}
	return (f->token->form);
}

int		get_token(t_state *f, int fd)
{
	char	*line;
	int		err;

	err = 1;
	if (get_next_line(fd, &line) == 1)
	{
		if (!ft_strncmp(line, "Piece ", 6))
		{
			f->y = ft_atoi(&line[6]);
			f->x = ft_atoi(ft_strchr(&line[6], ' '));
		}
		ft_strdel(&line);
	}
	if (f->y > 0 && f->x > 0 && (f->token = (t_token *)malloc(sizeof(t_token))))
	{
		f->token->h = f->y;
		f->token->w = f->x;
		f->y = -1;
		f->x = -1;
		f->token->form = init_form(f, f->token, fd, (size_t)(f->token->w));
		f->token->form ? err = 0 : 0;
	}
	err ? perror("Error: read token") : 0;
	return (err);
}

int		get_player(t_state *f, int fd)
{
	char	*line;
	int		err;
	int		ret;

	err = 1;
	if ((ret = get_next_line(fd, &line)) == 1)
	{
		if (!ft_strncmp(line, "$$$ exec p", 10))
		{
			err = 0;
			f->me = ft_strncmp(ft_strchr(line, 'p'), "p1", 2) ? 'X' : 'O';
			f->en = ft_strncmp(ft_strchr(line, 'p'), "p1", 2) ? 'O' : 'X';
		}
		ft_strdel(&line);
	}
	reset_state(f);
	(err || ret < 1) ? perror("Error: read player") : 0;
	return (err);
}
