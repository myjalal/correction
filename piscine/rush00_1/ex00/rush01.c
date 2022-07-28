/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raruiz-r <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:37:37 by raruiz-r          #+#    #+#             */
/*   Updated: 2022/02/27 22:25:54 by raruiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_putchar(char c);

void	ft_linefill(int v, int h, int x, int y)
{
	if ((h == 1 && v == 1) || (v == y && h == x && v != 1 && h != 1))
		ft_putchar('/');
	else if ((v == 1 && h == x) || (v == y && h == 1))
		ft_putchar('\\');
	else if ((h == 1 || h == x) && (v > 1 && v < y))
		ft_putchar('*');
	else if ((h > 1 && h < x) && (v == 1 || v == y))
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	v;
	int	h;

	if (x <= 0 || y <= 0)
		return ;
	v = 1;
	while (v <= y)
	{
		h = 1;
		while (h <= x)
		{
			ft_linefill(v, h, x, y);
			h++;
		}
		ft_putchar('\n');
		v++;
	}
}
