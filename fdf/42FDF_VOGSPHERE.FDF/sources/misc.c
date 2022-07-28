/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 17:48:37 by tshimoda          #+#    #+#             */
/*   Updated: 2021/12/31 18:19:21 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	hook_collection(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 1L << 0, key_event, fdf);
	mlx_hook(fdf->win, 17, 0, close_fdf, fdf);
}

void	fdf_line_len(t_fdf *fdf)
{
	if (fdf->nb_dots > 10000)
	{
		fdf->line_len = 1;
	}
	else if (fdf->nb_dots > 900)
	{
		fdf->line_len = 5;
	}
}

int	hex_to_dec(char *elements)
{
	int	nb;
	int	len;
	int	base;
	int	decimal;

	len = ft_strlen(elements) - 1;
	base = 1;
	decimal = 0;
	while (len >= 0)
	{
		if (ft_isdigit(elements[len]))
			nb = elements[len] - '0';
		else
			nb = ft_toupper(elements[len]) - 'A' + 10;
		decimal += nb * base;
		base *= 16;
		len--;
	}
	return (decimal);
}
