/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:56:54 by lmoreno           #+#    #+#             */
/*   Updated: 2022/01/27 15:22:53 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook_y(int key, t_game *game)
{
	int	j;

	j = 0;
	if (key == 1)
	{
		j = game->p_position.y + WIN_H;
		if (control_player_y(game, j))
		{
			game->p_position.y += WIN_H;
			game->moves++;
		}
	}
	else if (key == 13)
	{
		j = game->p_position.y - WIN_H;
		if (control_player_y(game, j))
		{
			game->p_position.y -= WIN_H;
			game->moves++;
		}
	}
}

void	key_hook_x(int key, t_game *game)
{
	int	j;

	j = 0;
	if (key == 2)
	{
		j = game->p_position.x + WIN_W;
		if (control_player_x(game, j))
		{
			game->p_position.x += WIN_W;
			game->moves++;
		}
	}
	else if (key == 0)
	{
		j = game->p_position.x - WIN_W;
		if (control_player_x(game, j))
		{
			game->p_position.x -= WIN_W;
			game->moves++;
		}
	}
}

int	key_hook(int key, t_game *game)
{
	key_hook_x(key, game);
	key_hook_y(key, game);
	if (key == 53)
		exit(0);
	render_start(game);
	return (0);
}
