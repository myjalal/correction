/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:55:00 by lmoreno           #+#    #+#             */
/*   Updated: 2021/12/20 13:48:08 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->moves = 0;
	game->control_exit = 0;
	new_window(game, "lmoreno So_Long");
	xpm_image(game);
	render_start(game);
	mlx_key_hook(game->wnd, key_hook, game);
	mlx_loop(game->mlx);
}
