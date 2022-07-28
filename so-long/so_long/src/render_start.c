/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:15:17 by lmoreno           #+#    #+#             */
/*   Updated: 2021/12/20 15:14:01 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	string_put(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->wnd,
		game->ensayo.id, 20, 35);
}

void	count_moves(t_game *game)
{
	if (game->moves != 0)
		ft_printf("Moves: %d\n", game->moves);
}

void	render_start(t_game *game)
{
	int	x;

	x = 0;
	mlx_clear_window(game->mlx, game->wnd);
	x = render_map_x(game);
	render_map_y(game, x);
	render_sprites(game);
	render_muro_inter(game);
	render_coin(game);
	count_moves(game);
	if (game->control_exit == 1)
	{
		string_put(game);
		game->control_exit = 0;
	}
}
