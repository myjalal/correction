/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raruiz-r <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:49:35 by raruiz-r          #+#    #+#             */
/*   Updated: 2022/02/27 20:02:39 by raruiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

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
			if (((v == 1 && h == 1) || (v == y && h == 1))
				|| ((v == 1 && h == x) || (v == y && h == x)))
				ft_putchar('o');
			else if (v == 1 || v == y)
				ft_putchar('-');
			else if (h == 1 || h == x)
				ft_putchar('|');
			else
				ft_putchar(' ');
		h++;
		}
		ft_putchar('\n');
				v++;
	}
}
