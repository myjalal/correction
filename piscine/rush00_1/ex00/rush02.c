/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raruiz-r <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:26:34 by raruiz-r          #+#    #+#             */
/*   Updated: 2022/02/27 22:29:38 by raruiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

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
			if ((v == 1 && h == 1) || (v == 1 && h == x))
				ft_putchar('A');
			else if ((v == y && h == 1) || (v == y && h == x))
				ft_putchar('C');
			else if (v == 1 || v == y || h == 1 || h == x)
				ft_putchar('B');
			else
				ft_putchar(' ');
			h++;
		}
		ft_putchar('\n');
		v++;
	}
}
