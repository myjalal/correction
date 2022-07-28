/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:34:26 by lmoreno           #+#    #+#             */
/*   Updated: 2021/12/20 12:34:00 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sprite	open_sprites(void *mlx, char *file)
{
	t_sprite	sprite;

	sprite.id = mlx_xpm_file_to_image(mlx, file, &sprite.size.x,
			&sprite.size.y);
	sprite.bits = mlx_get_data_addr(sprite.id, &sprite.bpp,
			&sprite.sz_line, &sprite.endian);
	return (sprite);
}

t_img_map	open_img_map(void *mlx, char *file)
{
	t_img_map	img_map;

	img_map.id = mlx_xpm_file_to_image(mlx, file,
			&img_map.size.x, &img_map.size.y);
	return (img_map);
}

void	xpm_image(t_game *game)
{
	game->edge_up = open_img_map(game->mlx, "sprites/grass1.xpm");
	game->centro = open_img_map(game->mlx, "sprites/centre.xpm");
	game->edge_up_dr = open_img_map(game->mlx,
			"sprites/grass_corner_right.xpm");
	game->edge_up_iz = open_img_map(game->mlx, "sprites/grass_corner_left.xpm");
	game->edge_dr = open_img_map(game->mlx, "sprites/edge_right.xpm");
	game->edge_iz = open_img_map(game->mlx, "sprites/edge_left.xpm");
	game->edge_bottom = open_img_map(game->mlx, "sprites/edge_bottom.xpm");
	game->exit = open_img_map(game->mlx, "sprites/exit.xpm");
	game->player = open_sprites(game->mlx, "sprites/ant_player.xpm");
	game->rock = open_img_map(game->mlx, "sprites/rock.xpm");
	game->coin = open_img_map(game->mlx, "sprites/coin1.xpm");
	game->ensayo = open_img_map(game->mlx, "sprites/exit_ensayo.xpm");
}
