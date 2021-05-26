/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_diouxp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mironbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 23:40:24 by mironbel          #+#    #+#             */
/*   Updated: 2020/08/13 02:59:37 by mironbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	make_align(int prefix, t_dir *x, int base)
{
	if (x->flag & F_MNS)
	{
		x->done += set_prefix(prefix, x, base);
		while (prefix && x->var > 0 && x->var--)
			x->done += write(x->fd, "0", 1);
		if (!prefix)
			while (x->temp > 0 && x->temp--)
				x->done += write(x->fd, " ", 1);
		return ;
	}
	if (x->flag & F_ZER)
	{
		x->done += set_prefix(prefix, x, base);
		while (x->temp > 0 && x->temp--)
			x->done += write(x->fd, "0", 1);
		while (x->var > 0 && x->var--)
			x->done += write(x->fd, "0", 1);
		return ;
	}
	while (x->temp > 0 && x->temp--)
		x->done += write(x->fd, " ", 1);
	x->done += set_prefix(prefix, x, base);
	while (x->var > 0 && x->var--)
		x->done += write(x->fd, "0", 1);
}

void	get_fill_di(t_dir *x, uintmax_t nb, int minus, int base)
{
	int	len;

	len = (int)ft_intlenb(nb, base);
	x->var = (len > x->precis) ? len : x->precis;
	x->var = x->var - len;
	x->temp = ((int)x->width > (len + x->var)) ? (int)x->width : len + x->var;
	x->temp = x->temp - x->var - len;
	(!nb && !ft_strchr("po", x->con)) ? x->flag &= ~F_HSH : 0;
	if (!nb && (x->con == 'o' && !x->precis && !(x->flag & DOT)))
		x->flag &= ~F_HSH;
	if (!(x->con = 0) && minus)
		x->con = '-';
	else if (x->flag & (F_PLS | F_SPC))
		x->con = (x->flag & F_PLS) ? '+' : ' ';
	(x->con) ? x->temp-- : 0;
	(!nb && !x->precis && x->flag & DOT && x->width) ? x->temp++ : 0;
	(x->var && base == 8) ? x->flag &= ~F_HSH : 0;
	if (x->flag & F_HSH)
		x->temp -= (base == 8) ? 1 : 2;
}

void	put_unb(t_dir *x)
{
	uintmax_t	nb;
	int			base;

	nb = 0;
	if (!x->size || x->size & S_T)
		nb = (!x->size) ? va_arg(x->arg, unsigned) :
		va_arg(x->arg, ptrdiff_t);
	else if (x->size & (S_J | S_Z))
		nb = (x->size & S_J) ? va_arg(x->arg, uintmax_t) :
			va_arg(x->arg, size_t);
	else if (x->size & (S_L | S_LL))
		nb = (x->size & S_L) ? va_arg(x->arg, unsigned long) :
			va_arg(x->arg, unsigned long long);
	if (x->size & (S_H | S_HH))
		nb = (x->size & S_HH) ? (unsigned char)va_arg(x->arg, unsigned) :
			(unsigned short)va_arg(x->arg, unsigned);
	(x->con == 'x') ? base = 16 : 0;
	(x->con == 'u') ? base = 10 : 0;
	(x->con == 'o') ? base = 8 : 0;
	get_fill_di(x, nb, 0, base);
	make_align(1, x, base);
	pf_print_base(nb, 0, base, x);
	make_align(0, x, base);
}

void	put_snb(t_dir *x)
{
	intmax_t	nb;
	int			minus;
	int			base;

	nb = 0;
	if (!x->size || x->size & S_T)
		nb = (!x->size) ? va_arg(x->arg, int) :
			va_arg(x->arg, ptrdiff_t);
	else if (x->size & (S_J | S_Z))
		nb = (x->size & S_J) ? va_arg(x->arg, intmax_t) :
			va_arg(x->arg, ssize_t);
	else if (x->size & (S_L | S_LL))
		nb = (x->size & S_L) ? va_arg(x->arg, long) :
			va_arg(x->arg, long long);
	else if (x->size & (S_H | S_HH))
		nb = (x->size & S_HH) ? (char)va_arg(x->arg, int) :
			(short)va_arg(x->arg, int);
	base = (x->con == 'd' || x->con == 'i') ? 10 : 0;
	minus = (nb < 0) ? 1 : 0;
	nb = (minus) ? (uintmax_t)(-nb) : (uintmax_t)nb;
	get_fill_di(x, nb, minus, base);
	make_align(1, x, base);
	pf_print_base(nb, minus, base, x);
	make_align(0, x, base);
}

void	put_pnb(t_dir *x)
{
	void *p;

	p = va_arg(x->arg, void *);
	get_fill_di(x, (uintmax_t)p, 0, 16);
	make_align(1, x, 16);
	pf_print_base((uintmax_t)p, 0, 16, x);
	make_align(0, x, 16);
}
