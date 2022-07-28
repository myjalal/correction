/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 22:25:23 by tshimoda          #+#    #+#             */
/*   Updated: 2021/12/31 18:19:43 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_dda_slope(t_fdf *fdf, t_dot *a, t_dot *b)
{
	int	i;

	i = 0;
	fdf->dot->x_dir = 1;
	fdf->dot->y_dir = 1;
	if (a[i].x > b[i].x)
		fdf->dot->x_dir = -1;
	if (a[i].y > b[i].y)
		fdf->dot->y_dir = -1;
	fdf->dot->dx = ft_absolute(b[i].x - a[i].x);
	fdf->dot->dy = ft_absolute(b[i].y - a[i].y);
	if (fdf->dot->dx > fdf->dot->dy)
		fdf->dot->steps = fdf->dot->dx;
	else
		fdf->dot->steps = fdf->dot->dy;
	fdf->dot->x_inc = fdf->dot->dx / fdf->dot->steps;
	fdf->dot->y_inc = fdf->dot->dy / fdf->dot->steps;
}

void	set_missing_dot_pos(int i, t_fdf *fdf)
{
	fdf->dot[i].missing = 1;
	fdf->dot[i].dcol = i % fdf->column;
	fdf->dot[i].drow = i / fdf->column;
	fdf->dot[i].x = (fdf->dot[i].dcol * fdf->line_len);
	fdf->dot[i].y = (fdf->dot[i].drow * fdf->line_len);
	fdf->dot[i].z = 0;
}

void	set_dot_position(char **elements, t_fdf *fdf)
{
	static int	i;
	int			pos;

	pos = 0;
	fdf_line_len(fdf);
	while (*elements && **elements != '\n')
	{
		fdf->dot[i].dcol = i % fdf->column;
		fdf->dot[i].drow = i / fdf->column;
		fdf->dot[i].x = (fdf->dot[i].dcol * fdf->line_len);
		fdf->dot[i].y = (fdf->dot[i].drow * fdf->line_len);
		fdf->dot[i].z = ft_atoi(*elements);
		fdf->dot[i].color = parse_color(*elements);
		fdf->dot[i].missing = 0;
		i++;
		pos++;
		elements++;
	}
	if (pos < (fdf->column))
		set_missing_dot_pos(i++, fdf);
}

void	connect_dots_loop(t_fdf *fdf, int i, double *x, double *y)
{
	while (fdf->dot->steps-- > 0)
	{
		my_mlx_pixel_put(fdf, round(*x), round(*y), fdf->dot[i].color);
		*x += (fdf->dot->x_dir * fdf->dot->x_inc);
		*y += (fdf->dot->y_dir * fdf->dot->y_inc);
	}
}

void	connect_dots(t_fdf *fdf)
{
	int		i;
	double	x;
	double	y;

	i = -1;
	refresh_map(fdf);
	while (++i < fdf->nb_dots)
	{
		x = fdf->dot[i].x;
		y = fdf->dot[i].y;
		if (round(x) < fdf->dot[i + 1].x && fdf->dot[i + 1].missing == 0)
		{
			get_dda_slope(fdf, &fdf->dot[i], &fdf->dot[i + 1]);
			connect_dots_loop(fdf, i, &x, &y);
		}
		x = fdf->dot[i].x;
		y = fdf->dot[i].y;
		if ((i + fdf->column < fdf->nb_dots) && \
		(fdf->dot[i].missing == 0 && fdf->dot[i + fdf->column].missing == 0))
		{
			get_dda_slope(fdf, &fdf->dot[i], &fdf->dot[i + fdf->column]);
			connect_dots_loop(fdf, i, &x, &y);
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
