/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mironbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 23:22:52 by mironbel          #+#    #+#             */
/*   Updated: 2020/08/12 23:29:55 by mironbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	parse_flag(t_dir *x)
{
	while ((x->var = ft_strchri(" 0+-'#$", *x->format)) > -1 && x->format++)
		x->flag |= (1 << x->var);
	(*x->format == '*' && x->format++) ? x->flag |= AST : 0;
	(x->flag & F_PLS) ? x->flag &= ~F_SPC : 0;
	if (x->flag & AST)
	{
		x->flag &= ~AST;
		x->var = (int)va_arg(x->arg, int);
		x->width = x->var;
		if (x->var < 0)
		{
			x->flag |= F_MNS;
			x->width = -x->var;
		}
	}
	(x->flag & F_MNS) ? x->flag &= ~F_ZER : 0;
}

void	parse_size(t_dir *x)
{
	x->size = 0;
	while (1)
	{
		if (*x->format == 'h')
			x->size |= (x->format[1] == 'h' && x->format++) ? S_HH : S_H;
		else if (*x->format == 't')
			x->size |= S_T;
		else if (*x->format == 'z')
			x->size |= S_Z;
		else if (*x->format == 'j')
			x->size |= S_J;
		else if (*x->format == 'l')
			x->size |= (x->format[1] == 'l' && x->format++) ? S_LL : S_L;
		else if (*x->format == 'w')
			x->size |= S_L;
		else if (*x->format == 'L')
			x->size |= S_LLL;
		else
			break ;
		x->format++;
	}
	parse_flag(x);
}

void	parse_width_precision(t_dir *x)
{
	x->precis = 0;
	if (*x->format > '0' && *x->format <= '9')
	{
		x->var = pf_atoi(&x->format);
		x->width = (x->var > 1) ? x->var : 1;
	}
	if (*x->format == '.')
	{
		x->flag |= DOT;
		x->var = 0;
		if (++x->format && *x->format == '*')
		{
			x->var = (int)va_arg(x->arg, int);
			x->format++;
			(x->var < 0) ? x->flag &= ~DOT : 0;
		}
		else
			x->var = pf_atoi(&x->format);
		x->precis = (x->var > 0) ? x->var : 0;
	}
}

void	map_conversion(t_dir *x)
{
	if (x->con == 's' && !(x->flag & UP) && !(x->size & (S_J | S_Z)))
		process_str(x);
	else if (ft_strchr("c%", x->con) && !(x->flag & UP))
		(x->con == '%') ? process_pct(x) : process_chr(x);
	else if (ft_strchr("diou", x->con) && !(x->flag & UP))
		ft_strchr("di", x->con) ? put_snb(x) : put_unb(x);
	else if (ft_strchr("xp", x->con))
		(x->con == 'x') ? put_unb(x) : put_pnb(x);
	else if (x->con == 'f')
		(x->size & S_LLL) ? put_nbl(x) : put_nbf(x);
}

void	parse_process(t_dir *x)
{
	x->flag = 0;
	x->width = 0;
	parse_flag(x);
	parse_width_precision(x);
	parse_size(x);
	(is_dirs(*x->format) == 1) ? x->flag |= UP : 0;
	x->con = (x->flag & UP) ? *x->format + 32 : *x->format;
	ft_strchr("oxup", x->con) ? x->flag &= ~(F_PLS | F_SPC) : 0;
	ft_strchr("diucs%", x->con) ? x->flag &= ~F_HSH : 0;
	if (ft_strchr("diuox", x->con))
		(x->flag & DOT) ? x->flag &= ~F_ZER : 0;
	(x->con == 'p') ? x->flag |= F_HSH : 0;
	if (x->precis <= (int)x->width && x->flag & DOT && !ft_strchr("sf", x->con))
		x->flag &= ~F_ZER;
	x->format++;
	map_conversion(x);
}
