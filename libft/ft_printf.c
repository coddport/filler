/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mironbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 23:18:14 by mironbel          #+#    #+#             */
/*   Updated: 2020/08/12 23:22:13 by mironbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	print(int is_dir, t_dir *x)
{
	if (is_dir == 1)
		parse_process(x);
	else if (is_dir == 0)
	{
		x->done += write(x->fd, x->format, x->i);
		x->format += x->i;
	}
}

void	ft_vfprintf(t_dir *x)
{
	int	is_dir;

	is_dir = 0;
	while (*x->format && !(is_dir < 0))
	{
		x->i = 0;
		is_dir = 0;
		if (x->format[x->i] == '%')
		{
			x->format++;
			if (!(is_dir = check_directive(x->format, &x->i)))
			{
				x->format += x->i;
				continue;
			}
		}
		else
			while (x->format[x->i] && x->format[x->i] != '%')
				x->i++;
		print(is_dir, x);
	}
}

int		ft_printf(const char *format, ...)
{
	t_dir	x;

	ft_bzero(&x, sizeof(x));
	x.format = (char *)format;
	x.fd = 1;
	va_start(x.arg, format);
	ft_vfprintf(&x);
	va_end(x.arg);
	return (x.done);
}
