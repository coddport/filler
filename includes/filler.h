/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <cport@student.21school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 21:39:32 by gcody             #+#    #+#             */
/*   Updated: 2020/11/16 15:08:38 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <stdio.h>
# include <errno.h>

typedef struct	s_map
{
	int			h;
	int			w;
	int			**proximity;
}				t_map;

typedef struct	s_token
{
	int			h;
	int			w;
	char		**form;
}				t_token;

typedef struct	s_state
{
	char		me;
	char		en;
	t_map		*map;
	t_token		*token;
	int			y;
	int			x;
}				t_state;

int				get_player(t_state *f, int fd);
int				get_map(t_state *f, int fd);
int				get_token(t_state *f, int fd);
void			*clean_map(t_state *f, int j);
void			*clean_token(t_state *f, int j);
void			reset_state(t_state *f);

#endif
