/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:49:18 by lmoreno           #+#    #+#             */
/*   Updated: 2021/12/16 10:55:33 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map(char *map)
{
	int	fd;

	if (!ft_strnstr(map, "ber", 20))
	{
		error("Invalid extension");
		return (0);
	}
	fd = open(map, O_RDONLY);
	return (fd);
}

/* Si llega a fallar realloc, implementar doble read
 * game.map_size.y = get_map_size_y(fd);
close (fd);
fd = open_map(map);
//position_init; */
t_game	init_map(char *map)
{
	t_game	game;
	int		fd;

	fd = open_map(map);
	if (fd == 0)
	{
		game.map = NULL;
		return (game);
	}
	parse_map(fd, &game);
	if (!check_map(&game))
	{
		game.map = NULL;
		return (game);
	}
	close(fd);
	return (game);
}
