/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:11:51 by smayrand          #+#    #+#             */
/*   Updated: 2022/02/27 16:11:36 by jpoint           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_printbox(int x, int y, int a, int b)
{
	if (x == 1 && y == 1)
		ft_putchar('A');
	else if (x == a && y == 1)
		ft_putchar('C');
	else if (x == 1 && y == b)
		ft_putchar('A');
	else if (x == a && y == b)
		ft_putchar('C');
	else if ((y == 1 || y == b) && (x < a && x > 1))
		ft_putchar('B');
	else if ((x == 1 || x == a) && (y < b && y > 1))
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int a, int b)
{
	int	x;
	int	y;

	if (a < 1 || b < 1)
		return ;
	y = 1;
	while (y <= b)
	{
		x = 1;
		while (x <= a)
		{
			ft_printbox(x, y, a, b);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
