/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:22:56 by lmoreno           #+#    #+#             */
/*   Updated: 2021/12/16 17:29:14 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(void)
{
	exit(0);
}

void	new_window(t_game *game, char *msg)
{
	game->wnd_sz.x = game->map_size.x * WIN_W;
	game->wnd_sz.y = game->map_size.y * WIN_H;
	game->wnd = mlx_new_window(game->mlx, game->wnd_sz.x, game->wnd_sz.y, msg);
	mlx_hook(game->wnd, 17, 0, ft_close, 0);
}
