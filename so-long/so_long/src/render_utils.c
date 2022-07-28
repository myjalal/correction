/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:26:24 by lmoreno           #+#    #+#             */
/*   Updated: 2021/12/20 15:11:05 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_muro_inter(t_game *game)
{
	int	y;
	int	x;

	y = 1;
	while (y < game->map_size.y - 1)
	{
		x = 1;
		while (x < game->map_size.x - 1)
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->wnd,
					game->rock.id, x * WIN_W, y * WIN_H);
			x++;
		}
		y++;
	}
}

void	render_coin(t_game *game)
{
	int	y;
	int	x;

	y = 1;
	while (y < game->map_size.y - 1)
	{
		x = 1;
		while (x < game->map_size.x - 1)
		{
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->wnd,
					game->coin.id, x * WIN_W, y * WIN_H);
			x++;
		}
		y++;
	}
}

void	render_sprites(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->wnd,
		game->player.id, game->p_position.x, game->p_position.y);
	mlx_put_image_to_window(game->mlx, game->wnd,
		game->exit.id, game->e_position.x, game->e_position.y);
}

int	render_map_x(t_game *game)
{
	int	x;
	int	y;

	x = 32;
	y = 32;
	mlx_put_image_to_window(game->mlx, game->wnd, game->edge_up_iz.id, 10, 20);
	while (x < (game->wnd_sz.x - 74))
	{
		mlx_put_image_to_window(game->mlx, game->wnd, game->edge_up.id, x, 20);
		x += 32;
	}
	while (y < (game->wnd_sz.y))
	{
		mlx_put_image_to_window(game->mlx, game->wnd, game->edge_iz.id, 10, y);
		y += 32;
	}
	mlx_put_image_to_window(game->mlx, game->wnd, game->edge_up_dr.id, x, 20);
	return (x);
}

void	render_map_y(t_game *game, int x)
{
	int	y;

	y = 32;
	while (y < (game->wnd_sz.y))
	{
		mlx_put_image_to_window(game->mlx, game->wnd, game->edge_dr.id, x, y);
		y += 32;
	}
	y = 52;
	while (y < game->wnd_sz.y)
	{
		x = 34;
		while (x < game->wnd_sz.x - 70)
		{
			mlx_put_image_to_window(game->mlx, game->wnd,
				game->centro.id, x, y);
			x += 32;
		}
		y += 32;
	}
}
