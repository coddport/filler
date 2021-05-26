/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mironbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 23:40:36 by mironbel          #+#    #+#             */
/*   Updated: 2020/08/13 02:59:06 by mironbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	process_str(t_dir *x)
{
	unsigned	*str;

	str = va_arg(x->arg, unsigned *);
	(!str) ? str = (unsigned *)"(null)" : 0;
	x->var = ft_strlen((char *)str);
	x->con = (x->flag & F_ZER) ? 48 : 32;
	if (x->flag & DOT)
		x->var = x->var > x->precis ? x->precis : x->var;
	if ((x->temp = x->width - x->var) < 1)
		x->done += write(x->fd, str, x->var);
	else if ((x->var = x->temp))
	{
		if (!(x->flag & F_MNS))
			while (x->temp--)
				x->done += write(x->fd, &x->con, 1);
		else
		{
			x->done += write(x->fd, str, x->width - x->var);
			while (x->temp--)
				x->done += write(x->fd, &x->con, 1);
			return ;
		}
		x->done += write(x->fd, str, x->width - x->var);
	}
}

void	process_chr(t_dir *x)
{
	unsigned	c;

	c = va_arg(x->arg, unsigned);
	x->con = (x->flag & F_ZER) ? 48 : 32;
	if ((x->temp = x->width - 1) < 1)
		x->done += write(x->fd, &c, 1);
	else if ((x->var = x->temp))
	{
		if (!(x->flag & F_MNS))
			while (x->temp--)
				x->done += write(x->fd, &x->con, 1);
		else
		{
			x->done += write(x->fd, &c, 1);
			while (x->temp--)
				x->done += write(x->fd, &x->con, 1);
			return ;
		}
		x->done += write(x->fd, &c, 1);
	}
}

void	process_pct(t_dir *x)
{
	unsigned	c;

	c = 37;
	x->con = (x->flag & F_ZER) ? 48 : 32;
	if ((x->temp = x->width - 1) < 1)
		x->done += write(x->fd, &c, 1);
	else if ((x->var = x->temp))
	{
		if (!(x->flag & F_MNS))
			while (x->temp--)
				x->done += write(x->fd, &x->con, 1);
		else
		{
			x->done += write(x->fd, &c, 1);
			while (x->temp--)
				x->done += write(x->fd, &x->con, 1);
			return ;
		}
		x->done += write(x->fd, &c, 1);
	}
}
