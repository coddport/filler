/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mironbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 23:45:29 by mironbel          #+#    #+#             */
/*   Updated: 2020/08/13 03:13:39 by mironbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		is_dirs(const char d)
{
	if (ft_strchr("diouxefgacspn%", d))
		return (0);
	else if (ft_strchr("DOUXEFGACS", d))
		return (1);
	else if (ft_strchr("'#-+0 ", d))
		return (2);
	else if (ft_strchr("hlzjLqt", d))
		return (3);
	else if (ft_strchr("$*.", d))
		return (4);
	else if (ft_strchr("123456789", d))
		return (5);
	return (-1);
}

int		check_directive(const char *str, size_t *i)
{
	while (str[*i] && (is_dirs(str[*i]) > 1))
		(*i)++;
	if (str[*i] && (!is_dirs(str[*i]) || is_dirs(str[*i]) == 1))
	{
		(*i)++;
		return (1);
	}
	if (!str[*i])
		return (-1);
	return (0);
}

int		pf_atoi(char **nptr)
{
	int		factor;
	long	res;

	factor = 1;
	res = 0;
	if (**nptr == '+' || **nptr == '-')
	{
		if (**nptr == '-')
			factor = -1;
	}
	while (**nptr >= '0' && **nptr <= '9')
		res = res * 10 + *(*nptr)++ - '0';
	return ((int)res * factor);
}

void	pf_print_base(uintmax_t num, int minus, int base, t_dir *x)
{
	uintmax_t temp;

	if (num == 0)
	{
		if (!(!x->precis && x->flag & DOT))
			x->done += write(x->fd, "0", 1);
		return ;
	}
	if (num > (unsigned)(base - 1))
		pf_print_base((num / base), minus, base, x);
	temp = num % base;
	if (temp >= 10 && temp <= 15)
	{
		if (!minus && (x->con = temp + ((x->flag & UP) ? 55 : 87)))
			x->done += write(x->fd, &x->con, 1);
		else if (minus && (x->con = temp + 55))
			x->done += write(x->fd, &x->con, 1);
	}
	else if (temp <= 9 && (x->con = temp + 48))
		x->done += write(x->fd, &x->con, 1);
}

int		set_prefix(int prefix, t_dir *x, int base)
{
	if (prefix)
	{
		if (x->con)
			return (write(x->fd, &x->con, 1));
		else if (x->flag & F_HSH && base == 16)
		{
			if (x->flag & UP)
				return (write(x->fd, "0X", 2));
			return (write(x->fd, "0x", 2));
		}
		else if (x->flag & F_HSH && base == 8)
			return (write(x->fd, "0", 1));
	}
	return (0);
}
