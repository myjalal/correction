/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:26:51 by jechekao          #+#    #+#             */
/*   Updated: 2022/02/26 18:51:35 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
/*1 = str, 2 = char*/
int	ft_putstr(char *s, char c, int i)
{
	int	count;

	count = 0;
	if (!s && i == 1)
		count += ft_putstr("(null)", 0, 1);
	else if (i == 2)
	{
		write(1, &c, 1);
		return (1);
	}
	else if (s && i == 1)
		while (s[count])
			count += ft_putstr(0, s[count], 2);
	return (count);
}

int	ft_putnum(long ln)
{
	int	x;

	x = 0;
	if (ln < 0)
	{
		x++;
		ln *= -1;
		ft_putstr(0, '-', 2);
	}
	if (ln > 9)
		x += ft_putnum(ln / 10);
	ft_putstr(0, ln % 10 + 48, 2);
	x++;
	return (x);
}

int	ft_printhex(unsigned long long ln, char conver)
{
	char	*base;
	char	*base_x;
	int		x;

	base = "0123456789abcdef";
	base_x = "0123456789ABCDEF";
	x = 0;
	if (conver == 'p' && ln / 16 > 0)
		x += ft_printhex(ln / 16, conver);
	if (conver == 'p')
		ft_putstr(0, base[ln % 16], 2);
	if (conver == 'x' && (unsigned int)ln / 16 > 0)
		x += ft_printhex((unsigned int)ln / 16, conver);
	if (conver == 'x')
		ft_putstr(0, base[ln % 16], 2);
	if (conver == 'X' && (unsigned int)ln / 16 > 0)
		x += ft_printhex((unsigned int)ln / 16, conver);
	if (conver == 'X')
		ft_putstr(0, base_x[ln % 16], 2);
	x++;
	return (x);
}

int	is_percent(va_list args, const char *conver)
{
	if (*conver == 's')
		return (ft_putstr(va_arg(args, char *), 0, 1));
	else if (*conver == 'c')
		return (ft_putstr(0, va_arg(args, int), 2));
	else if (*conver == 'p')
	{
		write(1, "0x", 2);
		return (ft_printhex(va_arg(args, unsigned long long), *conver) + 2);
	}
	else if (*conver == 'd' || *conver == 'i')
		return (ft_putnum(va_arg(args, int)));
	else if (*conver == 'u')
		return (ft_putnum(va_arg(args, unsigned int)));
	else if (*conver == 'x' || *conver == 'X')
		return (ft_printhex(va_arg(args, unsigned long long), *conver));
	else if (*conver == '%')
		return (ft_putstr(0, '%', 2));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		x;

	x = 0;
	if (!str || !*str)
		return (0);
	va_start (args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			x += is_percent(args, ++str);
			str++;
		}
		else
			x += ft_putstr(0, *str++, 2);
	}
	va_end(args);
	return (x);
}
