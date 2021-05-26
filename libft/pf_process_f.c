/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mironbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 02:27:34 by mironbel          #+#    #+#             */
/*   Updated: 2020/08/13 04:35:33 by mironbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	get_fill_f(t_dir *x, int minus, int len)
{
	if (!x->precis)
		(x->flag & DOT) ? (x->flag &= ~DOT) : (x->precis = 6);
	if (!(x->con = 0) && minus)
		x->con = '-';
	else if (x->flag & F_PLS || x->flag & F_SPC)
		x->con = (x->flag & F_PLS) ? '+' : ' ';
	x->var = len + (x->precis ? x->precis + 1 : 0) + ((x->con) ? 1 : 0);
	x->temp = (((int)x->width > x->var) ? (int)x->width : x->var) - x->var;
	x->temp -= (x->flag & F_HSH && !x->precis) ? 1 : 0;
	x->var = 0;
}

void	print_decimal(double nf, long double nl, t_dir *x)
{
	if (x->size & S_LLL)
	{
		nl = nl - (uintmax_t)nl;
		while (x->precis && x->precis--)
		{
			nl = nl * 10;
			x->con = (unsigned)((int)nl + 48);
			x->done += write(x->fd, &x->con, 1);
			nl = nl - (long double)((int)nl);
		}
		return ;
	}
	nf = nf - (uintmax_t)nf;
	while (x->precis && x->precis--)
	{
		nf = nf * 10;
		x->con = (unsigned)((int)nf + 48);
		x->done += write(x->fd, &x->con, 1);
		nf = nf - (double)((int)nf);
	}
}

void	put_nbf(t_dir *x)
{
	double		nf;
	int			len;

	nf = va_arg(x->arg, double);
	x->i = (nf < 0.0f) ? 1 : 0;
	len = ft_intlenb((uintmax_t)((x->i) ? -nf : nf), 10);
	get_fill_f(x, x->i, len);
	make_align(1, x, 10);
	pf_print_base((uintmax_t)((x->i) ? -nf : nf), x->i, 10, x);
	if (x->flag & (DOT | F_HSH) || x->precis)
	{
		x->done += write(x->fd, ".", 1);
		print_decimal((x->i) ? -nf : nf, 0, x);
	}
	make_align(0, x, 10);
}

void	put_nbl(t_dir *x)
{
	long double nf;
	int			len;

	nf = va_arg(x->arg, long double);
	x->i = (nf < 0.0l) ? 1 : 0;
	len = ft_intlenb((uintmax_t)((x->i) ? -nf : nf), 10);
	get_fill_f(x, x->i, len);
	make_align(1, x, 10);
	pf_print_base((uintmax_t)((x->i) ? -nf : nf), x->i, 10, x);
	if (x->flag & (DOT | F_HSH) || x->precis)
	{
		x->done += write(x->fd, ".", 1);
		print_decimal(0, (x->i) ? -nf : nf, x);
	}
	make_align(0, x, 10);
}
